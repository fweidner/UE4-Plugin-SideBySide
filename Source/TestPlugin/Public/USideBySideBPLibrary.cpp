#include "USideBySideBPLibrary.h"

#include "SideBySidePlugin.h"

#include "UStereoDeviceProvider.h"
#include "USideBySideStereoRenderingDevice.h"

const float DEFAULT_EYEOFFSET = 0.38000005f;
const float DEFAULT_PROJECTIONOFFSET = 0.151976421f / 10.f;

static bool bIsEditor = true;

bool USideBySideBPLibrary::Test()
{
	return true;
}

void USideBySideBPLibrary::SetEyeOffsetWithDelta(float _deltaOffset)
{
	if (bIsEditor)
		return;

	float currOffset = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		currOffset = tmpDevice->GetEyeOffset();
		tmpDevice->SetEyeOffset(currOffset + _deltaOffset);
	}
}

float USideBySideBPLibrary::GetEyeOffset()
{
	if (bIsEditor)
		return 3791.f;

	float res = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
		res = tmpDevice->GetEyeOffset();

	return res;
}

void USideBySideBPLibrary::SetEyeOffset(float _newEyeOffset)
{
	if (bIsEditor)
		return;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->SetEyeOffset(_newEyeOffset);
	}
}

void USideBySideBPLibrary::SetProjectionPlaneOffsetWithDelta(float _deltaProjectionOffset)
{
	if (bIsEditor)
		return;

	float currOffset = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		currOffset = tmpDevice->GetProjectionPlaneOffset();
		tmpDevice->SetProjectionPlaneOffset(currOffset + _deltaProjectionOffset);
	}
}

float USideBySideBPLibrary::GetProjectionPlaneOffset()
{
	if (bIsEditor)
		return 3791.f;

	float res = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
		res = tmpDevice->GetProjectionPlaneOffset();

	return res;

}

void USideBySideBPLibrary::SetProjectionPlaneOffset(float _newProjectionPLaneOffset)
{
	if (bIsEditor)
		return;


	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->SetProjectionPlaneOffset(_newProjectionPLaneOffset);
	}

}

void USideBySideBPLibrary::SetShowDebugMessage(bool _newVal)
{
	if (bIsEditor)
		return;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();


	if (tmpDevice)
	{
		tmpDevice->SetShowDebugMessage(_newVal);
	}
}

void USideBySideBPLibrary::IncFOV(float _FOVOffset)
{
	if (bIsEditor)
		return;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->IncFOV(_FOVOffset);
	}
}

void USideBySideBPLibrary::DecFOV(float _FOVOffset)
{
	if (bIsEditor)
		return;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->DecFOV(_FOVOffset);
	}
}

float USideBySideBPLibrary::GetFOV()
{
	if (bIsEditor)
		return 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();
	float res = 0.f;
	if (tmpDevice)
	{
		res = tmpDevice->GetFOV();
	}

	return res;
}

void USideBySideBPLibrary::SetNewFOV(float _newFOV)
{
	if (bIsEditor)
		return;
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();
	if (tmpDevice)
	{
		tmpDevice->SetNewFOV(_newFOV);
	}
}

void USideBySideBPLibrary::EnableStereo(bool _stereo)
{
	if (bIsEditor)
		return;
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->EnableStereo(_stereo);
	}
}

bool USideBySideBPLibrary::IsStereoEnabled()
{
	if (bIsEditor)
		return false;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();
	bool res = true;
	if (tmpDevice)
	{
		res = tmpDevice->IsStereoEnabled();
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////
bool USideBySideBPLibrary::SetIsEditor(bool _bIsEditor)
{
	bIsEditor = _bIsEditor;
	return bIsEditor;
}

bool USideBySideBPLibrary::GetIsEditor()
{
	return bIsEditor;
}

bool USideBySideBPLibrary::ToggleIsEditor()
{
	if (bIsEditor)
		bIsEditor = false;
	else
		bIsEditor = true;
	return bIsEditor;
}
