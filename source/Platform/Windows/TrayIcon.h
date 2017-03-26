#pragma once

#include <wtypes.h>

HWND CreateDummyTrayWindow(HINSTANCE hInstance);

void ShowApplicationIconInTray(HWND dummyTrayWindow);
void HideApplicationIconInTray(HWND dummyTrayWindow);