#ifdef _WINDOWS

#include <Platform/Windows/Main.h>

#include "Config.h"

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
) {
	return CustomGlobalHotkeys::Platform::Windows::Main(
		hInstance,
		hPrevInstance,
		lpCmdLine,
		nCmdShow,
		HOTKEYS_TO_REGISTER
	);
}

#endif