#include <windows.h>

#include <vector>

#include <Action/LambdaAction.h>
#include <Hotkey/Hotkey.h>

std::vector<Hotkey> CONFIG_HOTKEYS = {
	{
		MOD_ALT, 'S',
		std::shared_ptr<Action>(new LambdaAction(
			[]()
			{ 
				MessageBoxA(0, "XYZ", "123", MB_OK);
			}
		))
	},
	{
		MOD_ALT, 'A',
		std::shared_ptr<Action>(new LambdaAction(
			[]()
			{
				MessageBoxA(0, "Ahahaa", "123", MB_OK);
			}
		))
	}
};