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
#if WITH_EDITOR
	return;
#else
	float currOffset = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		currOffset = tmpDevice->GetEyeOffset();
		tmpDevice->SetEyeOffset(currOffset + _deltaOffset);
	}
#endif
	
}

float USideBySideBPLibrary::GetEyeOffset()
{
#if WITH_EDITOR
	return -1337.f;
#else
	float res = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
		res = tmpDevice->GetEyeOffset();

	return res;
#endif	
}

void USideBySideBPLibrary::SetEyeOffset(float _newEyeOffset)
{
#if WITH_EDITOR
	return;
#else
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->SetEyeOffset(_newEyeOffset);
	}
#endif

}

void USideBySideBPLibrary::SetProjectionOffsetWithDelta(float _deltaOffset)
{
#if WITH_EDITOR
	return;
#else
	float currOffset = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		currOffset = tmpDevice->GetProjectionCenterOffset();
		tmpDevice->SetProjectionCenterOffset(currOffset + _deltaOffset);
	}
#endif
	
}

float USideBySideBPLibrary::GetProjectionOffset()
{
#if WITH_EDITOR
	return -1337.f;
#else
	float res = 3791.f;

	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
		res = tmpDevice->GetProjectionCenterOffset();

	return res; 
#endif
	
}

void USideBySideBPLibrary::SetProjectionOffset(float _newProjectionOffset)
{
#if WITH_EDITOR
	return;
#else
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->SetProjectionCenterOffset(_newProjectionOffset);
	}
#endif
	
}

void USideBySideBPLibrary::SetShowDebugMessage(bool _newVal)
{
#if WITH_EDITOR
	return;
#else
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();


	if (tmpDevice)
	{
		tmpDevice->SetShowDebugMessage(_newVal);
	}

#endif	
}

void USideBySideBPLibrary::IncFOV(float _FOVOffset)
{
#if WITH_EDITOR
	return;
#else
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->IncFOV(_FOVOffset);
	}
#endif
	
}

void USideBySideBPLibrary::DecFOV(float _FOVOffset)
{
#if WITH_EDITOR
	return;
#else
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->DecFOV(_FOVOffset);
	}
#endif
	
}

float USideBySideBPLibrary::GetFOV()
{
#if WITH_EDITOR
	return -1337.f;
#else
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();
	float res = 0.f;
	if (tmpDevice)
	{
		res = tmpDevice->GetFOV();
	}

	return res; 
#endif
	
}

void USideBySideBPLibrary::SetNewFOV(float _newFOV)
{
#if WITH_EDITOR
	return;
#else
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();
	if (tmpDevice)
	{
		tmpDevice->SetNewFOV(_newFOV);
	}
#endif

}

void USideBySideBPLibrary::EnableStereo(bool _stereo)
{
#if WITH_EDITOR
	return;
#else
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();

	if (tmpDevice)
	{
		tmpDevice->EnableStereo(_stereo);
	}
#endif

}

bool USideBySideBPLibrary::IsStereoEnabled() 
{
#if WITH_EDITOR
	return false;
#else
	UStereoDeviceProvider* tmpProvider = UStereoDeviceProvider::GetInstance();
	USideBySideStereoRenderingDevice* tmpDevice = tmpProvider->GetStereoDevice();
	bool res = true;
	if (tmpDevice)
	{
		res = tmpDevice->IsStereoEnabled();
	}
	return res;
#endif	
}