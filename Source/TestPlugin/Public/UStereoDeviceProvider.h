#pragma once

#include "SideBySideStereoRenderingDevice.h"
#include "UStereoDeviceProvider.generated.h"


UCLASS()
class UStereoDeviceProvider : public UObject
{
public:

	GENERATED_BODY()

	static UStereoDeviceProvider* GetInstance();
	~UStereoDeviceProvider();

	USideBySideStereoRenderingDevice* GetStereoDevice();
	void SetStereoDevice(USideBySideStereoRenderingDevice* _tmp);

private:
	UStereoDeviceProvider();

	static UStereoDeviceProvider* MyProvider;

	USideBySideStereoRenderingDevice* MySBSStereoDevice;

};
