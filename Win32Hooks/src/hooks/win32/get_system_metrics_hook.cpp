#include "pch.h"
#include "hooks/win32/get_system_metrics_hook.h"
#include "settings/win32/get_system_metrics_settings.h"

// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics
static int(WINAPI* _GetSystemMetrics)(int nIndex) = GetSystemMetrics;

int WINAPI HK_GetSystemMetrics(int nIndex)
{
    // Get the user-defined value
    auto result = GetSystemMetricsHook::GetValueByIndex(nIndex);

    // Check if the value is undefined
    if (Settings::GetSystemMetrics::IsUndefined(result))
    {
        // Runs the original function
        return _GetSystemMetrics(nIndex);
    }

    // Returns the user-defined value
    return result;
}

void GetSystemMetricsHook::Attach()
{
    if (Settings::GetSystemMetrics::EnableHook)
    {
        DetourAttach(&(PVOID&)_GetSystemMetrics, HK_GetSystemMetrics);

        spdlog::info("GetSystemMetrics hook attached.");
    }
}

void GetSystemMetricsHook::Detach()
{
    if (Settings::GetSystemMetrics::EnableHook)
    {
        DetourDetach(&(PVOID&)_GetSystemMetrics, HK_GetSystemMetrics);

        spdlog::info("GetSystemMetrics hook detached.");
    }
}

int GetSystemMetricsHook::GetValueByIndex(int& nIndex)
{
    switch (nIndex)
    {
    case SM_ARRANGE:
        return Settings::GetSystemMetrics::sm_arrange;

    case SM_CLEANBOOT:
        return Settings::GetSystemMetrics::sm_cleanboot;

    case SM_CMONITORS:
        return Settings::GetSystemMetrics::sm_cmonitors;

    case SM_CMOUSEBUTTONS:
        return Settings::GetSystemMetrics::sm_cmousebuttons;

    case SM_CONVERTIBLESLATEMODE:
        return Settings::GetSystemMetrics::sm_convertibleslatemode;

    case SM_CXBORDER:
        return Settings::GetSystemMetrics::sm_cxborder;

    case SM_CXCURSOR:
        return Settings::GetSystemMetrics::sm_cxcursor;

    case SM_CXDLGFRAME:
        return !Settings::GetSystemMetrics::IsUndefined(Settings::GetSystemMetrics::sm_cxdlgframe)
            ? Settings::GetSystemMetrics::sm_cxdlgframe : Settings::GetSystemMetrics::sm_cxfixedframe;

    case SM_CXDOUBLECLK:
        return Settings::GetSystemMetrics::sm_cxdoubleclk;

    case SM_CXDRAG:
        return Settings::GetSystemMetrics::sm_cxdrag;

    case SM_CXEDGE:
        return Settings::GetSystemMetrics::sm_cxedge;

    case SM_CXFOCUSBORDER:
        return Settings::GetSystemMetrics::sm_cxfocusborder;

    case SM_CXFRAME:
        return !Settings::GetSystemMetrics::IsUndefined(Settings::GetSystemMetrics::sm_cxframe)
            ? Settings::GetSystemMetrics::sm_cxframe : Settings::GetSystemMetrics::sm_cxsizeframe;

    case SM_CXFULLSCREEN:
        return Settings::GetSystemMetrics::sm_cxfullscreen;

    case SM_CXHSCROLL:
        return Settings::GetSystemMetrics::sm_cxhscroll;

    case SM_CXHTHUMB:
        return Settings::GetSystemMetrics::sm_cxhthumb;

    case SM_CXICON:
        return Settings::GetSystemMetrics::sm_cxicon;

    case SM_CXICONSPACING:
        return Settings::GetSystemMetrics::sm_cxiconspacing;

    case SM_CXMAXIMIZED:
        return Settings::GetSystemMetrics::sm_cxmaximized;

    case SM_CXMAXTRACK:
        return Settings::GetSystemMetrics::sm_cxmaxtrack;

    case SM_CXMENUCHECK:
        return Settings::GetSystemMetrics::sm_cxmenucheck;

    case SM_CXMENUSIZE:
        return Settings::GetSystemMetrics::sm_cxmenusize;

    case SM_CXMIN:
        return Settings::GetSystemMetrics::sm_cxmin;

    case SM_CXMINIMIZED:
        return Settings::GetSystemMetrics::sm_cxminimized;

    case SM_CXMINSPACING:
        return Settings::GetSystemMetrics::sm_cxminspacing;

    case SM_CXMINTRACK:
        return Settings::GetSystemMetrics::sm_cxmintrack;

    case SM_CXPADDEDBORDER:
        return Settings::GetSystemMetrics::sm_cxpaddedborder;

    case SM_CXSCREEN:
        return Settings::GetSystemMetrics::sm_cxscreen;

    case SM_CXSIZE:
        return Settings::GetSystemMetrics::sm_cxsize;

    case SM_CXSMICON:
        return Settings::GetSystemMetrics::sm_cxsmicon;

    case SM_CXSMSIZE:
        return Settings::GetSystemMetrics::sm_cxsmsize;

    case SM_CXVIRTUALSCREEN:
        return Settings::GetSystemMetrics::sm_cxvirtualscreen;

    case SM_CXVSCROLL:
        return Settings::GetSystemMetrics::sm_cxvscroll;

    case SM_CYBORDER:
        return Settings::GetSystemMetrics::sm_cyborder;

    case SM_CYCAPTION:
        return Settings::GetSystemMetrics::sm_cycaption;

    case SM_CYCURSOR:
        return Settings::GetSystemMetrics::sm_cycursor;

    case SM_CYDLGFRAME:
        return !Settings::GetSystemMetrics::IsUndefined(Settings::GetSystemMetrics::sm_cydlgframe)
             ? Settings::GetSystemMetrics::sm_cydlgframe : Settings::GetSystemMetrics::sm_cyfixedframe;

    case SM_CYDOUBLECLK:
        return Settings::GetSystemMetrics::sm_cydoubleclk;

    case SM_CYDRAG:
        return Settings::GetSystemMetrics::sm_cydrag;

    case SM_CYEDGE:
        return Settings::GetSystemMetrics::sm_cyedge;

    case SM_CYFOCUSBORDER:
        return Settings::GetSystemMetrics::sm_cyfocusborder;

    case SM_CYFRAME:
        return !Settings::GetSystemMetrics::IsUndefined(Settings::GetSystemMetrics::sm_cyframe)
            ? Settings::GetSystemMetrics::sm_cyframe : Settings::GetSystemMetrics::sm_cysizeframe;

    case SM_CYFULLSCREEN:
        return Settings::GetSystemMetrics::sm_cyfullscreen;

    case SM_CYHSCROLL:
        return Settings::GetSystemMetrics::sm_cyhscroll;

    case SM_CYICON:
        return Settings::GetSystemMetrics::sm_cyicon;

    case SM_CYICONSPACING:
        return Settings::GetSystemMetrics::sm_cyiconspacing;

    case SM_CYKANJIWINDOW:
        return Settings::GetSystemMetrics::sm_cykanjiwindow;

    case SM_CYMAXIMIZED:
        return Settings::GetSystemMetrics::sm_cymaximized;

    case SM_CYMAXTRACK:
        return Settings::GetSystemMetrics::sm_cymaxtrack;

    case SM_CYMENU:
        return Settings::GetSystemMetrics::sm_cymenu;

    case SM_CYMENUCHECK:
        return Settings::GetSystemMetrics::sm_cymenucheck;

    case SM_CYMENUSIZE:
        return Settings::GetSystemMetrics::sm_cymenusize;

    case SM_CYMIN:
        return Settings::GetSystemMetrics::sm_cymin;

    case SM_CYMINIMIZED:
        return Settings::GetSystemMetrics::sm_cyminimized;

    case SM_CYMINSPACING:
        return Settings::GetSystemMetrics::sm_cyminspacing;

    case SM_CYMINTRACK:
        return Settings::GetSystemMetrics::sm_cymintrack;

    case SM_CYSCREEN:
        return Settings::GetSystemMetrics::sm_cyscreen;

    case SM_CYSIZE:
        return Settings::GetSystemMetrics::sm_cysize;

    case SM_CYSMCAPTION:
        return Settings::GetSystemMetrics::sm_cysmcaption;

    case SM_CYSMICON:
        return Settings::GetSystemMetrics::sm_cysmicon;

    case SM_CYSMSIZE:
        return Settings::GetSystemMetrics::sm_cysmsize;

    case SM_CYVIRTUALSCREEN:
        return Settings::GetSystemMetrics::sm_cyvirtualscreen;

    case SM_CYVSCROLL:
        return Settings::GetSystemMetrics::sm_cyvscroll;

    case SM_CYVTHUMB:
        return Settings::GetSystemMetrics::sm_cyvthumb;

    case SM_DBCSENABLED:
        return Settings::GetSystemMetrics::sm_dbcsenabled;

    case SM_DEBUG:
        return Settings::GetSystemMetrics::sm_debug;

    case SM_DIGITIZER:
        return Settings::GetSystemMetrics::sm_digitizer;

    case SM_IMMENABLED:
        return Settings::GetSystemMetrics::sm_immenabled;

    case SM_MAXIMUMTOUCHES:
        return Settings::GetSystemMetrics::sm_maximumtouches;

    case SM_MEDIACENTER:
        return Settings::GetSystemMetrics::sm_mediacenter;

    case SM_MENUDROPALIGNMENT:
        return Settings::GetSystemMetrics::sm_menudropalignment;

    case SM_MIDEASTENABLED:
        return Settings::GetSystemMetrics::sm_mideastenabled;

    case SM_MOUSEPRESENT:
        return Settings::GetSystemMetrics::sm_mousepresent;

    case SM_MOUSEHORIZONTALWHEELPRESENT:
        return Settings::GetSystemMetrics::sm_mousehorizontalwheelpresent;

    case SM_MOUSEWHEELPRESENT:
        return Settings::GetSystemMetrics::sm_mousewheelpresent;

    case SM_NETWORK:
        return Settings::GetSystemMetrics::sm_network;

    case SM_PENWINDOWS:
        return Settings::GetSystemMetrics::sm_penwindows;

    case SM_REMOTECONTROL:
        return Settings::GetSystemMetrics::sm_remotecontrol;

    case SM_REMOTESESSION:
        return Settings::GetSystemMetrics::sm_remotesession;

    case SM_SAMEDISPLAYFORMAT:
        return Settings::GetSystemMetrics::sm_samedisplayformat;

    case SM_SECURE:
        return Settings::GetSystemMetrics::sm_secure;

    case SM_SERVERR2:
        return Settings::GetSystemMetrics::sm_serverr2;

    case SM_SHOWSOUNDS:
        return Settings::GetSystemMetrics::sm_showsounds;

    case SM_SHUTTINGDOWN:
        return Settings::GetSystemMetrics::sm_shuttingdown;

    case SM_SLOWMACHINE:
        return Settings::GetSystemMetrics::sm_slowmachine;

    case SM_STARTER:
        return Settings::GetSystemMetrics::sm_starter;

    case SM_SWAPBUTTON:
        return Settings::GetSystemMetrics::sm_swapbutton;

    case SM_SYSTEMDOCKED:
        return Settings::GetSystemMetrics::sm_systemdocked;

    case SM_TABLETPC:
        return Settings::GetSystemMetrics::sm_tabletpc;

    case SM_XVIRTUALSCREEN:
        return Settings::GetSystemMetrics::sm_xvirtualscreen;

    case SM_YVIRTUALSCREEN:
        return Settings::GetSystemMetrics::sm_yvirtualscreen;
    }

    return Settings::GetSystemMetrics::UNDEFINED;
}
