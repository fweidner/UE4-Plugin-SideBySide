// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "StereoRendering.h"
#include "RHIStaticStates.h"

/**
*
*/
class USideBySideStereoRenderingDevice : public IStereoRendering
{
public:

	float FOVInDegrees;
	int32 Width, Height;

	USideBySideStereoRenderingDevice();
	virtual ~USideBySideStereoRenderingDevice() {};


	virtual bool IsStereoEnabled() const override;

	virtual bool EnableStereo(bool stereo = true);

	virtual void AdjustViewRect(EStereoscopicPass StereoPass, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const override;

	virtual void CalculateStereoViewOffset(const enum EStereoscopicPass StereoPassType, FRotator& ViewRotation, const float WorldToMeters, FVector& ViewLocation);

	virtual FMatrix GetStereoProjectionMatrix(const enum EStereoscopicPass StereoPassType) const;

	virtual void InitCanvasFromView(FSceneView* InView, UCanvas* Canvas) override {};
	
	//virtual void GetEyeRenderParams_RenderThread(const struct FRenderingCompositePassContext& Context, FVector2D& EyeToSrcUVScaleValue, FVector2D& EyeToSrcUVOffsetValue) const;

	virtual void RenderTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture2D* BackBuffer, FRHITexture2D* SrcTexture, FVector2D WindowSize) const override;

	float GetEyeOffset();
	void SetEyeOffset(float eyeOffset);

	float GetProjectionPlaneOffset();
	void SetProjectionPlaneOffset(float projectionCenterOffset);

	void SetShowDebugMessage(bool _newVal);

	//FOV
	void IncFOV(float _FOVOffset);
	void DecFOV(float _FOVOffset);
	float GetFOV() const;
	void SetNewFOV(float _newFOV);

private:
	//Horizontal spacing of cameras/eyes
	float EyeOffset = 3.20000005f; //0.38000005f;

	//HorizontalSpacing at near plane
	float ProjectionPlaneOffset = 0.03f;//0.151976421f;// / 10.f;

	bool bShowDebugMessage = false;

	bool bIs3D = false;

	int32 Eye = 0; // 0 = left, 1 = right ; 2 = cyclops
};