#pragma once

#include <wtypes.h>

namespace CustomGlobalHotkeys {
	namespace Platform {
		namespace Windows {
			namespace TrayIcon {
				HWND CreateDummyTrayWindow(HINSTANCE hInstance);

				void ShowApplicationIconInTray(HWND dummyTrayWindow);
				void HideApplicationIconInTray(HWND dummyTrayWindow);
			}
		}
	}
}