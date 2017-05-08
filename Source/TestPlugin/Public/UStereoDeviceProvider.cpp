#include "TestPlugin.h"

#include "UStereoDeviceProvider.h"


UStereoDeviceProvider* UStereoDeviceProvider::MyProvider = NULL;

UStereoDeviceProvider::UStereoDeviceProvider()
{

}

UStereoDeviceProvider* UStereoDeviceProvider::GetInstance()
{
	if (!MyProvider)
	{
		MyProvider = NewObject<UStereoDeviceProvider>();
		//MyProvider = ConstructObject(UStereoDeviceProvider*);
	}
	return MyProvider;
}

USideBySideStereoRenderingDevice* UStereoDeviceProvider::GetStereoDevice()
{
	return MySBSStereoDevice;
}

void UStereoDeviceProvider::SetStereoDevice(USideBySideStereoRenderingDevice* _tmp)
{
	MySBSStereoDevice = _tmp;
}

UStereoDeviceProvider::~UStereoDeviceProvider()
{
}
