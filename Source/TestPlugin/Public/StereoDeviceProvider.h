#pragma once
#include "SideBySideStereoRenderingDevice.h"

class StereoDeviceProvider
{
public:
	static StereoDeviceProvider* GetInstance();
	~StereoDeviceProvider();

	USideBySideStereoRenderingDevice* GetStereoDevice();
	void SetStereoDevice(USideBySideStereoRenderingDevice* _tmp);

private:
	StereoDeviceProvider();

	static StereoDeviceProvider* MyProvider;

	USideBySideStereoRenderingDevice* MySBSStereoDevice;

};
