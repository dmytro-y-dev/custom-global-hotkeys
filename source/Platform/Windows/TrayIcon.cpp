#include "TrayIcon.h"
#include <windows.h>

#include "../resource/resource.h"

#define WM_TRAYICON   (WM_USER + 1)
#define MENUITEM_EXIT 5000

static LPCSTR DummyTrayWindowClassName = "customGlobalHotkeysTrayDummyWindow";
static LPCSTR TrayIconTitle = "(metamaker) Custom Global Hotkeys";

static UINT ShowPopupMenu(HWND hwnd)
{
	POINT mousePosition;
	GetCursorPos(&mousePosition);

	SetForegroundWindow(hwnd);

	HMENU popupMenu = CreatePopupMenu();
	AppendMenu(popupMenu, MF_STRING, MENUITEM_EXIT, TEXT("Exit"));

	UINT selectedMenuItem = TrackPopupMenu(
		popupMenu,
		TPM_RETURNCMD | TPM_NONOTIFY,
		mousePosition.x,
		mousePosition.y,
		0,
		hwnd,
		NULL
	);

	DestroyMenu(popupMenu);

	return selectedMenuItem;
}

static LRESULT CALLBACK DummyTrayWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
		case WM_TRAYICON: {
			if (lParam == WM_RBUTTONDOWN) {
				if (ShowPopupMenu(hwnd) == MENUITEM_EXIT) {
					PostQuitMessage(0);
				}
			}
		} break;

		case WM_DESTROY: {
			PostQuitMessage(0);
		} break;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

HWND CreateDummyTrayWindow(HINSTANCE hInstance)
{
	WNDCLASSEXA wnd;
	memset(&wnd, 0, sizeof(wnd));

	wnd.cbSize = sizeof(WNDCLASSEX);
	wnd.hInstance = hInstance;
	wnd.lpszClassName = DummyTrayWindowClassName;
	wnd.lpfnWndProc = DummyTrayWindowProc;
	wnd.hIcon = LoadIconA(hInstance, MAKEINTRESOURCEA(IDI_APPLICATION));
	wnd.hIconSm = LoadIconA(hInstance, MAKEINTRESOURCEA(IDI_APPLICATION));
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (!RegisterClassExA(&wnd)) {
		FatalAppExit(0, TEXT("Couldn't register dummy tray window class!"));
	}

	return CreateWindowExA(
		0, DummyTrayWindowClassName,
		TrayIconTitle,
		0,
		0, 0,
		0, 0,
		NULL, NULL,
		hInstance, NULL
	);
}

void ShowApplicationIconInTray(HWND dummyTrayWindow)
{
	NOTIFYICONDATAA nid;
	memset(&nid, 0, sizeof(nid));

	nid.cbSize = sizeof(nid);
	nid.hWnd = dummyTrayWindow;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	strcpy(nid.szTip, TrayIconTitle);
	nid.hIcon = LoadIconA(GetModuleHandle(NULL), MAKEINTRESOURCEA(IDI_APPLICATION));
	nid.uCallbackMessage = WM_TRAYICON;

	Shell_NotifyIconA(NIM_ADD, &nid);
}

void HideApplicationIconInTray(HWND dummyTrayWindow)
{
	NOTIFYICONDATAA nid;
	memset(&nid, 0, sizeof(nid));

	nid.cbSize = sizeof(nid);
	nid.hWnd = dummyTrayWindow;

	Shell_NotifyIconA(NIM_DELETE, &nid);
}
