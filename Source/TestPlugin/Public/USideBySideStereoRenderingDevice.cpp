// Fill out your copyright notice in the Description page of Project Settings.
#include "USideBySideStereoRenderingDevice.h"

#include "SideBySidePlugin.h"

#include "Engine.h"
#include "UStereoDeviceProvider.h"

USideBySideStereoRenderingDevice::USideBySideStereoRenderingDevice()
	: FOVInDegrees(90)
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

	UStereoDeviceProvider* tmp = UStereoDeviceProvider::GetInstance();
	tmp->SetStereoDevice(this);
}

void USideBySideStereoRenderingDevice::AdjustViewRect(EStereoscopicPass StereoPass, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const
{
	SizeX = SizeX / 2;
	if (StereoPass == eSSP_RIGHT_EYE)
	{
		X += SizeX;
	}
	if (bShowDebugMessage)
	{
		GEngine->AddOnScreenDebugMessage(12, 1.f, FColor::Green, FString::Printf(TEXT("EyeOffset: %f"), EyeOffset));
		GEngine->AddOnScreenDebugMessage(13, 1.f, FColor::Green, FString::Printf(TEXT("ProjectionPlaneOffset: %f"), ProjectionPlaneOffset));
		GEngine->AddOnScreenDebugMessage(14, 1.f, FColor::Green, FString::Printf(TEXT("Height: %ld"), Height));
		GEngine->AddOnScreenDebugMessage(15, 1.f, FColor::Green, FString::Printf(TEXT("Width: %ld"), Width));
	}
}

void USideBySideStereoRenderingDevice::CalculateStereoViewOffset(const enum EStereoscopicPass StereoPassType, FRotator& ViewRotation, const float WorldToMeters, FVector& ViewLocation)
{
	if (StereoPassType != eSSP_FULL && StereoPassType != eSSP_MONOSCOPIC_EYE)
	{
		const float PassOffset = (StereoPassType == eSSP_LEFT_EYE) ? EyeOffset : -EyeOffset;
		ViewLocation += ViewRotation.Quaternion().RotateVector(FVector(0, PassOffset, 0));
	}
}

FMatrix USideBySideStereoRenderingDevice::GetStereoProjectionMatrix(const enum EStereoscopicPass StereoPassType) const
{

	const float InWidth = Width;
	const float InHeight = Height;
	const float InNearZ = GNearClippingPlane;

	float PassProjectionPlaneOffset = 0.f;
	if (bIs3D)
	{
		PassProjectionPlaneOffset = (StereoPassType == eSSP_LEFT_EYE) ? ProjectionPlaneOffset : -ProjectionPlaneOffset;
		

		const float HalfFov = FMath::DegreesToRadians(FOVInDegrees) / 2.f;
		const float XS = 1.0f / tan(HalfFov);
		const float YS = InWidth / tan(HalfFov) / InHeight;

		return FMatrix(
			FPlane(XS, 0.0f, 0.0f, 0.0f),
			FPlane(0.0f, YS, 0.0f, 0.0f),
			FPlane(0.0f, 0.0f, 0.0f, 1.0f),
			FPlane(0.0f, 0.0f, InNearZ, 0.0f))
			* FTranslationMatrix(FVector(PassProjectionPlaneOffset, 0, 0));


	}
	else //2D 
	{
		//FOV is not half FOV
		const float FOV = FMath::DegreesToRadians(FOVInDegrees);
		const float XS = 1.0f / tan(FOV);
		const float YS = InWidth / tan(FOV) / InHeight;

		return FMatrix(
			FPlane(XS, 0.0f, 0.0f, 0.0f),
			FPlane(0.0f, YS, 0.0f, 0.0f),
			FPlane(0.0f, 0.0f, 0.0f, 1.0f),
			FPlane(0.0f, 0.0f, InNearZ, 0.0f));
	}
}

void USideBySideStereoRenderingDevice::RenderTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture2D* BackBuffer, FRHITexture2D* SrcTexture, FVector2D WindowSize) const
{
	check(IsInRenderingThread());

	FRHIRenderTargetView BackBufferView = FRHIRenderTargetView(BackBuffer, ERenderTargetLoadAction::EClear);
	FRHISetRenderTargetsInfo Info(1, &BackBufferView, FRHIDepthRenderTargetView());
	RHICmdList.SetRenderTargetsAndClear(Info);
	const uint32 ViewportWidth = BackBuffer->GetSizeX();
	const uint32 ViewportHeight = BackBuffer->GetSizeY();
	RHICmdList.SetViewport(0, 0, 0, ViewportWidth, ViewportHeight, 1.0f);
}

float USideBySideStereoRenderingDevice::GetEyeOffset() {
	return EyeOffset;
}

float USideBySideStereoRenderingDevice::GetProjectionPlaneOffset() {
	return ProjectionPlaneOffset;
}

void USideBySideStereoRenderingDevice::SetEyeOffset(float eyeOffset) {
	EyeOffset = eyeOffset;
}

void USideBySideStereoRenderingDevice::SetProjectionPlaneOffset(float _projectionplaneoffset) {
	ProjectionPlaneOffset = _projectionplaneoffset;
}

void USideBySideStereoRenderingDevice::SetShowDebugMessage(bool _newVal)
{
	bShowDebugMessage = _newVal;
}

//////////////////////////////////////////////////////////////////////////
void USideBySideStereoRenderingDevice::IncFOV(float _FOVOffset)
{
	FOVInDegrees += _FOVOffset;
}

void USideBySideStereoRenderingDevice::DecFOV(float _FOVOffset)
{
	FOVInDegrees -= _FOVOffset;
}

float USideBySideStereoRenderingDevice::GetFOV() const
{
	return FOVInDegrees;
}

void USideBySideStereoRenderingDevice::SetNewFOV(float _newFOV)
{
	FOVInDegrees = _newFOV;
}

//////////////////////////////////////////////////////////////////////////
bool USideBySideStereoRenderingDevice::IsStereoEnabled() const
{
	return bIs3D;
}

bool USideBySideStereoRenderingDevice::EnableStereo(bool stereo)
{
	bool oldStereoState = bIs3D;
	bIs3D = stereo;
	return oldStereoState;
}
