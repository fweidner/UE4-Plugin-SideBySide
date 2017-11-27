#include "CustomGameEngine.h"

#include "SideBySidePlugin.h"


#include "USideBySideStereoRenderingDevice.h"
#include "Engine.h"

/*
wanna use me? add "GameEngine=/Script/TestPlugin.StereoRendering.CustomGameEngine" to DefaultEngine.ini under [/Script/Engine.Engine]
*/

bool UCustomGameEngine::InitializeHMDDevice()
{
	if (!IsRunningCommandlet())
	{
		if (!FParse::Param(FCommandLine::Get(), TEXT("nohmd")) && !IsRunningDedicatedServer())
		{
			TSharedPtr<USideBySideStereoRenderingDevice, ESPMode::ThreadSafe> FakeStereoDevice(new USideBySideStereoRenderingDevice());
			StereoRenderingDevice = FakeStereoDevice;
		}
	}

	return true;
}