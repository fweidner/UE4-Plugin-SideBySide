#include "USideBySideBPLibrary.h"

#include "SideBySidePlugin.h"

#include "UStereoDeviceProvider.h"
#include "USideBySideStereoRenderingDevice.h"

const float DEFAULT_EYEOFFSET = 0.38000005f;
const float DEFAULT_PROJECTIONOFFSET = 0.151976421f / 10.f;

bool USideBySideBPLibrary::Test()
{
	return true;
}

void USideBySideBPLibrary::SetEyeOffsetWithDelta(float _deltaOffset)
{
	float currOffset = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		currOffset = tmpDevice->GetEyeOffset();
		tmpDevice->SetEyeOffset(currOffset +  _deltaOffset);
	}
}

float USideBySideBPLibrary::GetEyeOffset()
{
	float res = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
		res = tmpDevice->GetEyeOffset();

	return res;
}

void USideBySideBPLibrary::SetEyeOffset(float _newEyeOffset)
{
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->SetEyeOffset(_newEyeOffset);
	}
}

void USideBySideBPLibrary::SetProjectionOffsetWithDelta(float _deltaOffset)
{
	float currOffset = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		currOffset = tmpDevice->GetProjectionCenterOffset();
		tmpDevice->SetProjectionCenterOffset(currOffset +  _deltaOffset);
	}
}

float USideBySideBPLibrary::GetProjectionOffset()
{
	float res = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
		res = tmpDevice->GetProjectionCenterOffset();

	return res;
}

void USideBySideBPLibrary::SetProjectionOffset(float _newProjectionOffset)
{
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->SetProjectionCenterOffset(_newProjectionOffset);
	}
}

void USideBySideBPLibrary::SetShowDebugMessage(bool _newVal)
{
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();


	if (tmpDevice)
	{
		tmpDevice->SetShowDebugMessage(_newVal);
	}
}

void USideBySideBPLibrary::IncFOV(float _FOVOffset)
{
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->IncFOV(_FOVOffset);
	}
}

void USideBySideBPLibrary::DecFOV(float _FOVOffset)
{
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->DecFOV(_FOVOffset);
	}
}

float USideBySideBPLibrary::GetFOV()
{
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();
	float res = 0.f;
	if (tmpDevice)
	{
		res = tmpDevice->GetFOV();
	}

	return res;
}

void USideBySideBPLibrary::EnableStereo(bool _stereo)
{
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->EnableStereo(_stereo);
	}
}

bool USideBySideBPLibrary::IsStereoEnabled() 
{
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();
	bool res = true;
	if (tmpDevice)
	{
		res = tmpDevice->IsStereoEnabled();
	}
	return res;
}