#ifdef _WINDOWS

#include <Platform/Windows/Main.h>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
) {
	return Main(
		hInstance,
		hPrevInstance,
		lpCmdLine,
		nCmdShow
	);
}

#endif