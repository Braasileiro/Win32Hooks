#include "pch.h"
#include "hooks/get_system_metrics_hook.h"
#include "settings/get_system_metrics_settings.h"

// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics
static int(WINAPI* _GetSystemMetrics)(int nIndex) = GetSystemMetrics;

int WINAPI HK_GetSystemMetrics(int nIndex)
{
    // Get the user-defined value
    auto result = GetSystemMetricsHook::GetValueByIndex(nIndex);

    // Check if the value is undefined
    if (SGetSystemMetrics::IsUndefined(result))
    {
        // Runs the original function
        return _GetSystemMetrics(nIndex);
    }

    // Returns the user-defined value
    return result;
}

void GetSystemMetricsHook::Attach()
{
    if (SGetSystemMetrics::EnableHook)
    {
        DetourAttach(&(PVOID&)_GetSystemMetrics, HK_GetSystemMetrics);

        spdlog::info("GetSystemMetrics hook attached.");
    }
}

void GetSystemMetricsHook::Detach()
{
    if (SGetSystemMetrics::EnableHook)
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
        return SGetSystemMetrics::sm_arrange;

    case SM_CLEANBOOT:
        return SGetSystemMetrics::sm_cleanboot;

    case SM_CMONITORS:
        return SGetSystemMetrics::sm_cmonitors;

    case SM_CMOUSEBUTTONS:
        return SGetSystemMetrics::sm_cmousebuttons;

    case SM_CONVERTIBLESLATEMODE:
        return SGetSystemMetrics::sm_convertibleslatemode;

    case SM_CXBORDER:
        return SGetSystemMetrics::sm_cxborder;

    case SM_CXCURSOR:
        return SGetSystemMetrics::sm_cxcursor;

    case SM_CXDLGFRAME:
        return !SGetSystemMetrics::IsUndefined(SGetSystemMetrics::sm_cxdlgframe)
            ? SGetSystemMetrics::sm_cxdlgframe : SGetSystemMetrics::sm_cxfixedframe;

    case SM_CXDOUBLECLK:
        return SGetSystemMetrics::sm_cxdoubleclk;

    case SM_CXDRAG:
        return SGetSystemMetrics::sm_cxdrag;

    case SM_CXEDGE:
        return SGetSystemMetrics::sm_cxedge;

    case SM_CXFOCUSBORDER:
        return SGetSystemMetrics::sm_cxfocusborder;

    case SM_CXFRAME:
        return !SGetSystemMetrics::IsUndefined(SGetSystemMetrics::sm_cxframe)
            ? SGetSystemMetrics::sm_cxframe : SGetSystemMetrics::sm_cxsizeframe;

    case SM_CXFULLSCREEN:
        return SGetSystemMetrics::sm_cxfullscreen;

    case SM_CXHSCROLL:
        return SGetSystemMetrics::sm_cxhscroll;

    case SM_CXHTHUMB:
        return SGetSystemMetrics::sm_cxhthumb;

    case SM_CXICON:
        return SGetSystemMetrics::sm_cxicon;

    case SM_CXICONSPACING:
        return SGetSystemMetrics::sm_cxiconspacing;

    case SM_CXMAXIMIZED:
        return SGetSystemMetrics::sm_cxmaximized;

    case SM_CXMAXTRACK:
        return SGetSystemMetrics::sm_cxmaxtrack;

    case SM_CXMENUCHECK:
        return SGetSystemMetrics::sm_cxmenucheck;

    case SM_CXMENUSIZE:
        return SGetSystemMetrics::sm_cxmenusize;

    case SM_CXMIN:
        return SGetSystemMetrics::sm_cxmin;

    case SM_CXMINIMIZED:
        return SGetSystemMetrics::sm_cxminimized;

    case SM_CXMINSPACING:
        return SGetSystemMetrics::sm_cxminspacing;

    case SM_CXMINTRACK:
        return SGetSystemMetrics::sm_cxmintrack;

    case SM_CXPADDEDBORDER:
        return SGetSystemMetrics::sm_cxpaddedborder;

    case SM_CXSCREEN:
        return SGetSystemMetrics::sm_cxscreen;

    case SM_CXSIZE:
        return SGetSystemMetrics::sm_cxsize;

    case SM_CXSMICON:
        return SGetSystemMetrics::sm_cxsmicon;

    case SM_CXSMSIZE:
        return SGetSystemMetrics::sm_cxsmsize;

    case SM_CXVIRTUALSCREEN:
        return SGetSystemMetrics::sm_cxvirtualscreen;

    case SM_CXVSCROLL:
        return SGetSystemMetrics::sm_cxvscroll;

    case SM_CYBORDER:
        return SGetSystemMetrics::sm_cyborder;

    case SM_CYCAPTION:
        return SGetSystemMetrics::sm_cycaption;

    case SM_CYCURSOR:
        return SGetSystemMetrics::sm_cycursor;

    case SM_CYDLGFRAME:
        return !SGetSystemMetrics::IsUndefined(SGetSystemMetrics::sm_cydlgframe)
            ? SGetSystemMetrics::sm_cydlgframe : SGetSystemMetrics::sm_cyfixedframe;

    case SM_CYDOUBLECLK:
        return SGetSystemMetrics::sm_cydoubleclk;

    case SM_CYDRAG:
        return SGetSystemMetrics::sm_cydrag;

    case SM_CYEDGE:
        return SGetSystemMetrics::sm_cyedge;

    case SM_CYFOCUSBORDER:
        return SGetSystemMetrics::sm_cyfocusborder;

    case SM_CYFRAME:
        return !SGetSystemMetrics::IsUndefined(SGetSystemMetrics::sm_cyframe)
            ? SGetSystemMetrics::sm_cyframe : SGetSystemMetrics::sm_cysizeframe;

    case SM_CYFULLSCREEN:
        return SGetSystemMetrics::sm_cyfullscreen;

    case SM_CYHSCROLL:
        return SGetSystemMetrics::sm_cyhscroll;

    case SM_CYICON:
        return SGetSystemMetrics::sm_cyicon;

    case SM_CYICONSPACING:
        return SGetSystemMetrics::sm_cyiconspacing;

    case SM_CYKANJIWINDOW:
        return SGetSystemMetrics::sm_cykanjiwindow;

    case SM_CYMAXIMIZED:
        return SGetSystemMetrics::sm_cymaximized;

    case SM_CYMAXTRACK:
        return SGetSystemMetrics::sm_cymaxtrack;

    case SM_CYMENU:
        return SGetSystemMetrics::sm_cymenu;

    case SM_CYMENUCHECK:
        return SGetSystemMetrics::sm_cymenucheck;

    case SM_CYMENUSIZE:
        return SGetSystemMetrics::sm_cymenusize;

    case SM_CYMIN:
        return SGetSystemMetrics::sm_cymin;

    case SM_CYMINIMIZED:
        return SGetSystemMetrics::sm_cyminimized;

    case SM_CYMINSPACING:
        return SGetSystemMetrics::sm_cyminspacing;

    case SM_CYMINTRACK:
        return SGetSystemMetrics::sm_cymintrack;

    case SM_CYSCREEN:
        return SGetSystemMetrics::sm_cyscreen;

    case SM_CYSIZE:
        return SGetSystemMetrics::sm_cysize;

    case SM_CYSMCAPTION:
        return SGetSystemMetrics::sm_cysmcaption;

    case SM_CYSMICON:
        return SGetSystemMetrics::sm_cysmicon;

    case SM_CYSMSIZE:
        return SGetSystemMetrics::sm_cysmsize;

    case SM_CYVIRTUALSCREEN:
        return SGetSystemMetrics::sm_cyvirtualscreen;

    case SM_CYVSCROLL:
        return SGetSystemMetrics::sm_cyvscroll;

    case SM_CYVTHUMB:
        return SGetSystemMetrics::sm_cyvthumb;

    case SM_DBCSENABLED:
        return SGetSystemMetrics::sm_dbcsenabled;

    case SM_DEBUG:
        return SGetSystemMetrics::sm_debug;

    case SM_DIGITIZER:
        return SGetSystemMetrics::sm_digitizer;

    case SM_IMMENABLED:
        return SGetSystemMetrics::sm_immenabled;

    case SM_MAXIMUMTOUCHES:
        return SGetSystemMetrics::sm_maximumtouches;

    case SM_MEDIACENTER:
        return SGetSystemMetrics::sm_mediacenter;

    case SM_MENUDROPALIGNMENT:
        return SGetSystemMetrics::sm_menudropalignment;

    case SM_MIDEASTENABLED:
        return SGetSystemMetrics::sm_mideastenabled;

    case SM_MOUSEPRESENT:
        return SGetSystemMetrics::sm_mousepresent;

    case SM_MOUSEHORIZONTALWHEELPRESENT:
        return SGetSystemMetrics::sm_mousehorizontalwheelpresent;

    case SM_MOUSEWHEELPRESENT:
        return SGetSystemMetrics::sm_mousewheelpresent;

    case SM_NETWORK:
        return SGetSystemMetrics::sm_network;

    case SM_PENWINDOWS:
        return SGetSystemMetrics::sm_penwindows;

    case SM_REMOTECONTROL:
        return SGetSystemMetrics::sm_remotecontrol;

    case SM_REMOTESESSION:
        return SGetSystemMetrics::sm_remotesession;

    case SM_SAMEDISPLAYFORMAT:
        return SGetSystemMetrics::sm_samedisplayformat;

    case SM_SECURE:
        return SGetSystemMetrics::sm_secure;

    case SM_SERVERR2:
        return SGetSystemMetrics::sm_serverr2;

    case SM_SHOWSOUNDS:
        return SGetSystemMetrics::sm_showsounds;

    case SM_SHUTTINGDOWN:
        return SGetSystemMetrics::sm_shuttingdown;

    case SM_SLOWMACHINE:
        return SGetSystemMetrics::sm_slowmachine;

    case SM_STARTER:
        return SGetSystemMetrics::sm_starter;

    case SM_SWAPBUTTON:
        return SGetSystemMetrics::sm_swapbutton;

    case SM_SYSTEMDOCKED:
        return SGetSystemMetrics::sm_systemdocked;

    case SM_TABLETPC:
        return SGetSystemMetrics::sm_tabletpc;

    case SM_XVIRTUALSCREEN:
        return SGetSystemMetrics::sm_xvirtualscreen;

    case SM_YVIRTUALSCREEN:
        return SGetSystemMetrics::sm_yvirtualscreen;
    }

    return SGetSystemMetrics::UNDEFINED;
}
