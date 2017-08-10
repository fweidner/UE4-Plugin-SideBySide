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
	~USideBySideStereoRenderingDevice() {};


	virtual bool IsStereoEnabled() const override { return true; };

	virtual bool EnableStereo(bool stereo = true) override { return true; };

	virtual void AdjustViewRect(EStereoscopicPass StereoPass, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const override;

	virtual void CalculateStereoViewOffset(const enum EStereoscopicPass StereoPassType, const FRotator& ViewRotation, const float WorldToMeters, FVector& ViewLocation) override;

	virtual FMatrix GetStereoProjectionMatrix(const enum EStereoscopicPass StereoPassType, const float FOV) const override;

	virtual void InitCanvasFromView(FSceneView* InView, UCanvas* Canvas) override {};
	
	
	//TODO test this.
	virtual void GetEyeRenderParams_RenderThread(const struct FRenderingCompositePassContext& Context, FVector2D& EyeToSrcUVScaleValue, FVector2D& EyeToSrcUVOffsetValue) const;

	virtual bool ShouldUseSeparateRenderTarget() const override;

	virtual void RenderTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef SrcTexture) const override;

	// Custom methods
	float GetEyeOffset();
	void SetEyeOffset(float eyeOffset);

	float GetProjectionCenterOffset();
	void SetProjectionCenterOffset(float projectionCenterOffset);

	void SetShowDebugMessage(bool _newVal);
private:
	//Horizontal spacing of cameras/eyes
	float EyeOffset = 3.20000005f; //0.38000005f;

	//HorizontalSpacing at near plane
	float ProjectionCenterOffset = 0.03f;//0.151976421f;// / 10.f;

	bool bShowDebugMessage = false;
};
