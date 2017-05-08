#include "TestPlugin.h"

#include "USideBySideBPLibrary.h"
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

void USideBySideBPLibrary::IncProjectionOffsetWithDelta(float _deltaOffset)
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

