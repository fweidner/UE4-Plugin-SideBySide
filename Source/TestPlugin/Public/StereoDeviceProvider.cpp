#include "TestPlugin.h"

#include "StereoDeviceProvider.h"


StereoDeviceProvider* StereoDeviceProvider::MyProvider = NULL;

StereoDeviceProvider::StereoDeviceProvider()
{

}

StereoDeviceProvider* StereoDeviceProvider::GetInstance()
{
	if (!MyProvider)
	{
		MyProvider = new StereoDeviceProvider();
	}
	return MyProvider;
}

USideBySideStereoRenderingDevice* StereoDeviceProvider::GetStereoDevice()
{
	return MySBSStereoDevice;
}

void StereoDeviceProvider::SetStereoDevice(USideBySideStereoRenderingDevice* _tmp)
{
	MySBSStereoDevice = _tmp;
}

StereoDeviceProvider::~StereoDeviceProvider()
{
}
