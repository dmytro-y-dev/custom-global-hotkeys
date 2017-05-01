#pragma once

#include <windows.h>
#include <vector>

#include <Abstract/Hotkey/Hotkey.h>

namespace CustomGlobalHotkeys {
	namespace Platform {
		namespace Windows {
			using CustomGlobalHotkeys::Hotkey::Hotkey;

			int Main(
				HINSTANCE hInstance,
				HINSTANCE hPrevInstance,
				LPSTR lpCmdLine,
				int nCmdShow,
				const std::vector<Hotkey>& hotkeys
			);
		}
	}
} 
