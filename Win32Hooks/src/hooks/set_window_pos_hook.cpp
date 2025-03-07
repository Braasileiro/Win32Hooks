#include "pch.h"
#include "hooks/set_window_pos_hook.h"
#include "settings/set_window_pos_settings.h"

// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowpos
static BOOL(WINAPI* _SetWindowPos)(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags) = SetWindowPos;

BOOL WINAPI HK_SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags)
{
    if (!Settings::SetWindowPos::DisableAlwaysOnTop)
    {
        return _SetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags);
    }

    return _SetWindowPos(hWnd, HWND_NOTOPMOST, X, Y, cx, cy, uFlags);
}

void SetWindowPosHook::Attach()
{
    if (Settings::SetWindowPos::EnableHook)
    {
        DetourAttach(&(PVOID&)_SetWindowPos, HK_SetWindowPos);

        spdlog::info("SetWindowPos hook attached.");
    }
}

void SetWindowPosHook::Detach()
{
    if (Settings::SetWindowPos::EnableHook)
    {
        DetourDetach(&(PVOID&)_SetWindowPos, HK_SetWindowPos);

        spdlog::info("SetWindowPos hook detached.");
    }
}
