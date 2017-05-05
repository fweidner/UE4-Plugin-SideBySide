#include "TestPlugin.h"

#include "CustomGameEngine.h"

#include "SideBySideStereoRenderingDevice.h"
//#include "ActiveStereoRenderingDevice.h"
#include "Engine.h"

/*
[PROJECTNAME]
wanna use me? add "GameEngine=/Script/Car2Simulate.StereoRendering.CustomGameEngine" to DefaultEngine.ini under [/Script/Engine.Engine]
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