#include "SideBySidePlugin.h"

#include "UStereoDeviceProvider.h"

#include <assert.h>     /* assert */
#include "Engine/Engine.h"

UStereoDeviceProvider* UStereoDeviceProvider::MyProvider = NULL;

UStereoDeviceProvider::UStereoDeviceProvider()
{

}

UStereoDeviceProvider* UStereoDeviceProvider::GetInstance()
{
	if (!MyProvider)
	{
		MyProvider = new UStereoDeviceProvider();
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
