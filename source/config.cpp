#include <windows.h>

#include <vector>

#include <Action/LambdaAction.h>
#include <Hotkey/Hotkey.h>
#include <Platform/Windows/Action/ExecuteFileAction.h>

using CustomGlobalHotkeys::Hotkey::Hotkey;
using CustomGlobalHotkeys::Action::TActionSharedPtr;
using CustomGlobalHotkeys::Platform::Windows::Action::ExecuteFileAction;

std::vector<Hotkey> CONFIG_HOTKEYS = {
	{
		0, VK_PAUSE, new ExecuteFileAction(
			L"E:\\Projects\\Workroom\\ODG\\Start Workspace.bat"
		)
	}
};