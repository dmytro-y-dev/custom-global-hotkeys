#include <windows.h>
#include <iostream>
#include <vector>

#include <HotkeyManager/HotkeyManager.h>

using std::cout;

extern std::vector<Hotkey> CONFIG_HOTKEYS;

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
) {
	HotkeyManager hotkeyManager;

	// Register hotkeys

	for each (Hotkey hotkey in CONFIG_HOTKEYS) {
		hotkeyManager.registerHotkey(hotkey);
	}

	// Listen for registered hotkeys to be pressed

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0) != 0)
	{
		if (msg.message == WM_HOTKEY)
		{
			THotkeyIdentifier hotkeyId = msg.wParam;

			std::shared_ptr<Action> action = hotkeyManager.findActionByHotkey(hotkeyId);

			if (action) {
				action->execute();
			}
		}
	}

	return 0;
}