#include "pch.h"
#include "hooks/get_device_caps_hook.h"
#include "settings/get_device_caps_settings.h"

// https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getdevicecaps
static int(WINAPI* _GetDeviceCaps)(HDC hdc, int index) = GetDeviceCaps;

int WINAPI HK_GetDeviceCaps(HDC hdc, int index)
{
    // Get the user-defined value
    auto result = GetDeviceCapsHook::GetValueByIndex(index);

    // Check if the value is undefined
    if (SGetDeviceCaps::IsUndefined(result))
    {
        // Runs the original function
        return _GetDeviceCaps(hdc, index);
    }

    // Returns the user-defined value
    return result;
}

void GetDeviceCapsHook::Attach()
{
    if (SGetDeviceCaps::EnableHook)
    {
        DetourAttach(&(PVOID&)_GetDeviceCaps, HK_GetDeviceCaps);

        spdlog::info("GetDeviceCaps hook attached.");
    }
}

void GetDeviceCapsHook::Detach()
{
    if (SGetDeviceCaps::EnableHook)
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
        return SGetDeviceCaps::driverversion;
        break;

    case TECHNOLOGY:
        return SGetDeviceCaps::technology;
        break;

    case HORZSIZE:
        return SGetDeviceCaps::horzsize;
        break;

    case VERTSIZE:
        return SGetDeviceCaps::vertsize;
        break;

    case HORZRES:
        return SGetDeviceCaps::horzres;
        break;

    case VERTRES:
        return SGetDeviceCaps::vertres;
        break;

    case BITSPIXEL:
        return SGetDeviceCaps::bitspixel;
        break;

    case PLANES:
        return SGetDeviceCaps::planes;
        break;

    case NUMBRUSHES:
        return SGetDeviceCaps::numbrushes;
        break;

    case NUMPENS:
        return SGetDeviceCaps::numpens;
        break;

    case NUMMARKERS:
        return SGetDeviceCaps::nummarkers;
        break;

    case NUMFONTS:
        return SGetDeviceCaps::numfonts;
        break;

    case NUMCOLORS:
        return SGetDeviceCaps::numcolors;
        break;

    case PDEVICESIZE:
        return SGetDeviceCaps::pdevicesize;
        break;

    case CURVECAPS:
        return SGetDeviceCaps::curvecaps;
        break;

    case LINECAPS:
        return SGetDeviceCaps::linecaps;
        break;

    case POLYGONALCAPS:
        return SGetDeviceCaps::polygonalcaps;
        break;

    case TEXTCAPS:
        return SGetDeviceCaps::textcaps;
        break;

    case CLIPCAPS:
        return SGetDeviceCaps::clipcaps;
        break;

    case RASTERCAPS:
        return SGetDeviceCaps::rastercaps;
        break;

    case ASPECTX:
        return SGetDeviceCaps::aspectx;
        break;

    case ASPECTY:
        return SGetDeviceCaps::aspecty;
        break;

    case ASPECTXY:
        return SGetDeviceCaps::aspectxy;
        break;

    case LOGPIXELSX:
        return SGetDeviceCaps::logpixelsx;
        break;

    case LOGPIXELSY:
        return SGetDeviceCaps::logpixelsy;
        break;

    case SIZEPALETTE:
        return SGetDeviceCaps::sizepalette;
        break;

    case NUMRESERVED:
        return SGetDeviceCaps::numreserved;
        break;

    case COLORRES:
        return SGetDeviceCaps::colorres;
        break;

    case PHYSICALWIDTH:
        return SGetDeviceCaps::physicalwidth;
        break;

    case PHYSICALHEIGHT:
        return SGetDeviceCaps::physicalheight;
        break;

    case PHYSICALOFFSETX:
        return SGetDeviceCaps::physicaloffsetx;
        break;

    case PHYSICALOFFSETY:
        return SGetDeviceCaps::physicaloffsety;
        break;

    case SCALINGFACTORX:
        return SGetDeviceCaps::scalingfactorx;
        break;

    case SCALINGFACTORY:
        return SGetDeviceCaps::scalingfactory;
        break;

    case VREFRESH:
        return SGetDeviceCaps::vrefresh;
        break;

    case DESKTOPVERTRES:
        return SGetDeviceCaps::desktopvertres;
        break;

    case DESKTOPHORZRES:
        return SGetDeviceCaps::desktophorzres;
        break;

    case BLTALIGNMENT:
        return SGetDeviceCaps::bltalignment;
        break;

    case SHADEBLENDCAPS:
        return SGetDeviceCaps::shadeblendcaps;
        break;

    case COLORMGMTCAPS:
        return SGetDeviceCaps::colormgmtcaps;
        break;
    }

    return SGetDeviceCaps::UNDEFINED;
}
