#include <windows.h>

#include <Abstract/Action/LambdaAction.h>
#include <Platform/Windows/Action/ExecuteFileAction.h>

#include "Config.h"

using CustomGlobalHotkeys::Platform::Windows::Action::ExecuteFileAction;

std::vector<Hotkey> HOTKEYS_TO_REGISTER = {
	{
		0, VK_PAUSE, new ExecuteFileAction(
			L"E:\\Projects\\Workroom\\ODG\\Start Workspace.bat"
		)
	}
};