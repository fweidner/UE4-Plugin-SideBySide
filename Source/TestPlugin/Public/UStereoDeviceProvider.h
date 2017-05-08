#pragma once

#include "USideBySideStereoRenderingDevice.h"


class UStereoDeviceProvider 
{
public:

	static UStereoDeviceProvider* GetInstance();

	~UStereoDeviceProvider();

	USideBySideStereoRenderingDevice* GetStereoDevice();
	void SetStereoDevice(USideBySideStereoRenderingDevice* _tmp);

private:
	UStereoDeviceProvider();

	static UStereoDeviceProvider* MyProvider;

	USideBySideStereoRenderingDevice* MySBSStereoDevice;

};
