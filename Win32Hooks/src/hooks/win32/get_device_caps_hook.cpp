#include "pch.h"
#include "hooks/win32/get_device_caps_hook.h"
#include "settings/win32/get_device_caps_settings.h"

// https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getdevicecaps
static int(WINAPI* _GetDeviceCaps)(HDC hdc, int index) = GetDeviceCaps;

int WINAPI HK_GetDeviceCaps(HDC hdc, int index)
{
    // Get the user-defined value
    auto result = GetDeviceCapsHook::GetValueByIndex(index);

    // Check if the value is undefined
    if (Settings::GetDeviceCaps::IsUndefined(result))
    {
        // Runs the original function
        return _GetDeviceCaps(hdc, index);
    }

    // Returns the user-defined value
    return result;
}

void GetDeviceCapsHook::Attach()
{
    if (Settings::GetDeviceCaps::EnableHook)
    {
        DetourAttach(&(PVOID&)_GetDeviceCaps, HK_GetDeviceCaps);

        spdlog::info("GetDeviceCaps hook attached.");
    }
}

void GetDeviceCapsHook::Detach()
{
    if (Settings::GetDeviceCaps::EnableHook)
    {
        DetourDetach(&(PVOID&)_GetDeviceCaps, HK_GetDeviceCaps);

        spdlog::info("GetDeviceCaps hook detached.");
    }
}

int GetDeviceCapsHook::GetValueByIndex(int& index)
{
    switch (index)
    {
    case DRIVERVERSION:
        return Settings::GetDeviceCaps::driverversion;
        break;

    case TECHNOLOGY:
        return Settings::GetDeviceCaps::technology;
        break;

    case HORZSIZE:
        return Settings::GetDeviceCaps::horzsize;
        break;

    case VERTSIZE:
        return Settings::GetDeviceCaps::vertsize;
        break;

    case HORZRES:
        return Settings::GetDeviceCaps::horzres;
        break;

    case VERTRES:
        return Settings::GetDeviceCaps::vertres;
        break;

    case BITSPIXEL:
        return Settings::GetDeviceCaps::bitspixel;
        break;

    case PLANES:
        return Settings::GetDeviceCaps::planes;
        break;

    case NUMBRUSHES:
        return Settings::GetDeviceCaps::numbrushes;
        break;

    case NUMPENS:
        return Settings::GetDeviceCaps::numpens;
        break;

    case NUMMARKERS:
        return Settings::GetDeviceCaps::nummarkers;
        break;

    case NUMFONTS:
        return Settings::GetDeviceCaps::numfonts;
        break;

    case NUMCOLORS:
        return Settings::GetDeviceCaps::numcolors;
        break;

    case PDEVICESIZE:
        return Settings::GetDeviceCaps::pdevicesize;
        break;

    case CURVECAPS:
        return Settings::GetDeviceCaps::curvecaps;
        break;

    case LINECAPS:
        return Settings::GetDeviceCaps::linecaps;
        break;

    case POLYGONALCAPS:
        return Settings::GetDeviceCaps::polygonalcaps;
        break;

    case TEXTCAPS:
        return Settings::GetDeviceCaps::textcaps;
        break;

    case CLIPCAPS:
        return Settings::GetDeviceCaps::clipcaps;
        break;

    case RASTERCAPS:
        return Settings::GetDeviceCaps::rastercaps;
        break;

    case ASPECTX:
        return Settings::GetDeviceCaps::aspectx;
        break;

    case ASPECTY:
        return Settings::GetDeviceCaps::aspecty;
        break;

    case ASPECTXY:
        return Settings::GetDeviceCaps::aspectxy;
        break;

    case LOGPIXELSX:
        return Settings::GetDeviceCaps::logpixelsx;
        break;

    case LOGPIXELSY:
        return Settings::GetDeviceCaps::logpixelsy;
        break;

    case SIZEPALETTE:
        return Settings::GetDeviceCaps::sizepalette;
        break;

    case NUMRESERVED:
        return Settings::GetDeviceCaps::numreserved;
        break;

    case COLORRES:
        return Settings::GetDeviceCaps::colorres;
        break;

    case PHYSICALWIDTH:
        return Settings::GetDeviceCaps::physicalwidth;
        break;

    case PHYSICALHEIGHT:
        return Settings::GetDeviceCaps::physicalheight;
        break;

    case PHYSICALOFFSETX:
        return Settings::GetDeviceCaps::physicaloffsetx;
        break;

    case PHYSICALOFFSETY:
        return Settings::GetDeviceCaps::physicaloffsety;
        break;

    case SCALINGFACTORX:
        return Settings::GetDeviceCaps::scalingfactorx;
        break;

    case SCALINGFACTORY:
        return Settings::GetDeviceCaps::scalingfactory;
        break;

    case VREFRESH:
        return Settings::GetDeviceCaps::vrefresh;
        break;

    case DESKTOPVERTRES:
        return Settings::GetDeviceCaps::desktopvertres;
        break;

    case DESKTOPHORZRES:
        return Settings::GetDeviceCaps::desktophorzres;
        break;

    case BLTALIGNMENT:
        return Settings::GetDeviceCaps::bltalignment;
        break;

    case SHADEBLENDCAPS:
        return Settings::GetDeviceCaps::shadeblendcaps;
        break;

    case COLORMGMTCAPS:
        return Settings::GetDeviceCaps::colormgmtcaps;
        break;
    }

    return Settings::GetDeviceCaps::UNDEFINED;
}
