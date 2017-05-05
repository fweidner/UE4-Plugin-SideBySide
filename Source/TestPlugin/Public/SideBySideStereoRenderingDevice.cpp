// Fill out your copyright notice in the Description page of Project Settings.
#include "TestPlugin.h"

#include "SideBySideStereoRenderingDevice.h"
#include "Engine.h"
#include "StereoDeviceProvider.h"

USideBySideStereoRenderingDevice::USideBySideStereoRenderingDevice()
	: FOVInDegrees(110)
	, Width(2560)
	, Height(1600)
{
	static TAutoConsoleVariable<float> CVarEmulateStereoFOV(TEXT("r.StereoEmulationFOV"), 0, TEXT("FOV in degrees, of the imaginable HMD for stereo emulation"));
	static TAutoConsoleVariable<int32> CVarEmulateStereoWidth(TEXT("r.StereoEmulationWidth"), 0, TEXT("Width of the imaginable HMD for stereo emulation"));
	static TAutoConsoleVariable<int32> CVarEmulateStereoHeight(TEXT("r.StereoEmulationHeight"), 0, TEXT("Height of the imaginable HMD for stereo emulation"));
	float FOV = CVarEmulateStereoFOV.GetValueOnAnyThread();
	if (FOV != 0)
	{
		FOVInDegrees = FMath::Clamp(FOV, 20.f, 300.f);
	}
	int32 W = CVarEmulateStereoWidth.GetValueOnAnyThread();
	int32 H = CVarEmulateStereoHeight.GetValueOnAnyThread();
	if (W != 0)
	{
		Width = FMath::Clamp(W, 100, 10000);
	}
	if (H != 0)
	{
		Height = FMath::Clamp(H, 100, 10000);
	}

	StereoDeviceProvider* tmp = StereoDeviceProvider::GetInstance();
	tmp->SetStereoDevice(this);
}

void USideBySideStereoRenderingDevice::AdjustViewRect(EStereoscopicPass StereoPass, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const
{
	SizeX = SizeX / 2;
	if (StereoPass == eSSP_RIGHT_EYE)
	{
		X += SizeX;
	}
	GEngine->AddOnScreenDebugMessage(12, 1.f, FColor::Green, FString::Printf(TEXT("EyeOffset: %f"), EyeOffset));
	GEngine->AddOnScreenDebugMessage(13, 1.f, FColor::Green, FString::Printf(TEXT("ProjectionCenterOffset: %f"), ProjectionCenterOffset));
}

void USideBySideStereoRenderingDevice::CalculateStereoViewOffset(const enum EStereoscopicPass StereoPassType, const FRotator& ViewRotation, const float WorldToMeters, FVector& ViewLocation)
{
	if (StereoPassType != eSSP_FULL)
	{
		const float PassOffset = (StereoPassType == eSSP_LEFT_EYE) ? EyeOffset : -EyeOffset;
		ViewLocation += ViewRotation.Quaternion().RotateVector(FVector(0, PassOffset, 0));
	}
}

FMatrix USideBySideStereoRenderingDevice::GetStereoProjectionMatrix(const enum EStereoscopicPass StereoPassType, const float FOV) const
{

	const float PassProjectionOffset = (StereoPassType == eSSP_LEFT_EYE) ? ProjectionCenterOffset : -ProjectionCenterOffset;

	const float HalfFov = FMath::DegreesToRadians(FOVInDegrees) / 2.f;
	const float InWidth = Width;
	const float InHeight = Height;
	const float XS = 1.0f / tan(HalfFov);
	const float YS = InWidth / tan(HalfFov) / InHeight;

	const float InNearZ = GNearClippingPlane;
	return FMatrix(
		FPlane(XS, 0.0f, 0.0f, 0.0f),
		FPlane(0.0f, YS, 0.0f, 0.0f),
		FPlane(0.0f, 0.0f, 0.0f, 1.0f),
		FPlane(0.0f, 0.0f, InNearZ, 0.0f))

		* FTranslationMatrix(FVector(PassProjectionOffset, 0, 0));

}

void USideBySideStereoRenderingDevice::GetEyeRenderParams_RenderThread(const struct FRenderingCompositePassContext& Context, FVector2D& EyeToSrcUVScaleValue, FVector2D& EyeToSrcUVOffsetValue) const
{
	EyeToSrcUVOffsetValue = FVector2D::ZeroVector;
	EyeToSrcUVScaleValue = FVector2D(1.0f, 1.0f);
}

bool USideBySideStereoRenderingDevice::ShouldUseSeparateRenderTarget() const
{
	// should return true to test rendering into a separate texture; however, there is a bug
	// in DrawNormalizedScreenQuad (FScreenVS shader), TTP #338597, so false for now.
	return false; //true; 
}

void USideBySideStereoRenderingDevice::RenderTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef SrcTexture) const
{
	check(IsInRenderingThread());

	//RHISetRenderTarget( BackBuffer, FTextureRHIRef() );
	SetRenderTarget(RHICmdList, BackBuffer, FTextureRHIRef());
	const uint32 ViewportWidth = BackBuffer->GetSizeX();
	const uint32 ViewportHeight = BackBuffer->GetSizeY();
	RHICmdList.SetViewport(0, 0, 0, ViewportWidth, ViewportHeight, 1.0f);


	//RHICmdList.SetBlendState(TStaticBlendState<>::GetRHI());
	RHICmdList.SetRasterizerState(TStaticRasterizerState<>::GetRHI());
	RHICmdList.SetDepthStencilState(TStaticDepthStencilState<false, CF_Always>::GetRHI());
	//RHICmdList.Clear(true, FLinearColor::Black, false, 0, false, 0, FIntRect()); //HACK: untested for side-by-side mode
}

float USideBySideStereoRenderingDevice::GetEyeOffset() {
	return EyeOffset;
}

float USideBySideStereoRenderingDevice::GetProjectionCenterOffset() {
	return ProjectionCenterOffset;
}

void USideBySideStereoRenderingDevice::SetEyeOffset(float eyeOffset) {
	EyeOffset = eyeOffset;
}

void USideBySideStereoRenderingDevice::SetProjectionCenterOffset(float projectionCenterOffset) {
	ProjectionCenterOffset = projectionCenterOffset;
}