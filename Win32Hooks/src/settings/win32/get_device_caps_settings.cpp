#include "pch.h"
#include "settings/win32/get_device_caps_settings.h"

using namespace Settings;

bool GetDeviceCaps::EnableHook;
int GetDeviceCaps::driverversion;
int GetDeviceCaps::technology;
int GetDeviceCaps::horzsize;
int GetDeviceCaps::vertsize;
int GetDeviceCaps::horzres;
int GetDeviceCaps::vertres;
int GetDeviceCaps::bitspixel;
int GetDeviceCaps::planes;
int GetDeviceCaps::numbrushes;
int GetDeviceCaps::numpens;
int GetDeviceCaps::nummarkers;
int GetDeviceCaps::numfonts;
int GetDeviceCaps::numcolors;
int GetDeviceCaps::pdevicesize;
int GetDeviceCaps::curvecaps;
int GetDeviceCaps::linecaps;
int GetDeviceCaps::polygonalcaps;
int GetDeviceCaps::textcaps;
int GetDeviceCaps::clipcaps;
int GetDeviceCaps::rastercaps;
int GetDeviceCaps::aspectx;
int GetDeviceCaps::aspecty;
int GetDeviceCaps::aspectxy;
int GetDeviceCaps::logpixelsx;
int GetDeviceCaps::logpixelsy;
int GetDeviceCaps::sizepalette;
int GetDeviceCaps::numreserved;
int GetDeviceCaps::colorres;
int GetDeviceCaps::physicalwidth;
int GetDeviceCaps::physicalheight;
int GetDeviceCaps::physicaloffsetx;
int GetDeviceCaps::physicaloffsety;
int GetDeviceCaps::scalingfactorx;
int GetDeviceCaps::scalingfactory;
int GetDeviceCaps::vrefresh;
int GetDeviceCaps::desktopvertres;
int GetDeviceCaps::desktophorzres;
int GetDeviceCaps::bltalignment;
int GetDeviceCaps::shadeblendcaps;
int GetDeviceCaps::colormgmtcaps;

void GetDeviceCaps::Load(toml::table& table)
{
    auto section = table["GetDeviceCaps"];

    EnableHook = section["EnableHook"].value_or(false);

    if (EnableHook)
    {
        driverversion = section["DRIVERVERSION"].value_or(UNDEFINED);
        technology = section["TECHNOLOGY"].value_or(UNDEFINED);
        horzsize = section["HORZSIZE"].value_or(UNDEFINED);
        vertsize = section["VERTSIZE"].value_or(UNDEFINED);
        horzres = section["HORZRES"].value_or(UNDEFINED);
        vertres = section["VERTRES"].value_or(UNDEFINED);
        bitspixel = section["BITSPIXEL"].value_or(UNDEFINED);
        planes = section["PLANES"].value_or(UNDEFINED);
        numbrushes = section["NUMBRUSHES"].value_or(UNDEFINED);
        numpens = section["NUMPENS"].value_or(UNDEFINED);
        nummarkers = section["NUMMARKERS"].value_or(UNDEFINED);
        numfonts = section["NUMFONTS"].value_or(UNDEFINED);
        numcolors = section["NUMCOLORS"].value_or(UNDEFINED);
        pdevicesize = section["PDEVICESIZE"].value_or(UNDEFINED);
        curvecaps = section["CURVECAPS"].value_or(UNDEFINED);
        linecaps = section["LINECAPS"].value_or(UNDEFINED);
        polygonalcaps = section["POLYGONALCAPS"].value_or(UNDEFINED);
        textcaps = section["TEXTCAPS"].value_or(UNDEFINED);
        clipcaps = section["CLIPCAPS"].value_or(UNDEFINED);
        rastercaps = section["RASTERCAPS"].value_or(UNDEFINED);
        aspectx = section["ASPECTX"].value_or(UNDEFINED);
        aspecty = section["ASPECTY"].value_or(UNDEFINED);
        aspectxy = section["ASPECTXY"].value_or(UNDEFINED);
        logpixelsx = section["LOGPIXELSX"].value_or(UNDEFINED);
        logpixelsy = section["LOGPIXELSY"].value_or(UNDEFINED);
        sizepalette = section["SIZEPALETTE"].value_or(UNDEFINED);
        numreserved = section["NUMRESERVED"].value_or(UNDEFINED);
        colorres = section["COLORRES"].value_or(UNDEFINED);
        physicalwidth = section["PHYSICALWIDTH"].value_or(UNDEFINED);
        physicalheight = section["PHYSICALHEIGHT"].value_or(UNDEFINED);
        physicaloffsetx = section["PHYSICALOFFSETX"].value_or(UNDEFINED);
        physicaloffsety = section["PHYSICALOFFSETY"].value_or(UNDEFINED);
        scalingfactorx = section["SCALINGFACTORX"].value_or(UNDEFINED);
        scalingfactory = section["SCALINGFACTORY"].value_or(UNDEFINED);
        vrefresh = section["VREFRESH"].value_or(UNDEFINED);
        desktopvertres = section["DESKTOPVERTRES"].value_or(UNDEFINED);
        desktophorzres = section["DESKTOPHORZRES"].value_or(UNDEFINED);
        bltalignment = section["BLTALIGNMENT"].value_or(UNDEFINED);
        shadeblendcaps = section["SHADEBLENDCAPS"].value_or(UNDEFINED);
        colormgmtcaps = section["COLORMGMTCAPS"].value_or(UNDEFINED);

        spdlog::info("Describing 'GetDeviceCaps' settings...");
        spdlog::info("--------------------------------------");
        Describe();
        spdlog::info("--------------------------------------");
    }
}

bool GetDeviceCaps::IsUndefined(int& value)
{
    return value == UNDEFINED;
}

void GetDeviceCaps::Describe()
{
    // YandereDev style

    if (!IsUndefined(driverversion))
    {
        spdlog::info("DRIVERVERSION is '{}'.", driverversion);
    }

    if (!IsUndefined(technology))
    {
        spdlog::info("TECHNOLOGY is '{}'.", technology);
    }

    if (!IsUndefined(horzsize))
    {
        spdlog::info("HORZSIZE is '{}'.", horzsize);
    }

    if (!IsUndefined(vertsize))
    {
        spdlog::info("VERTSIZE is '{}'.", vertsize);
    }

    if (!IsUndefined(horzres))
    {
        spdlog::info("HORZRES is '{}'.", horzres);
    }

    if (!IsUndefined(vertres))
    {
        spdlog::info("VERTRES is '{}'.", vertres);
    }

    if (!IsUndefined(bitspixel))
    {
        spdlog::info("BITSPIXEL is '{}'.", bitspixel);
    }

    if (!IsUndefined(planes))
    {
        spdlog::info("PLANES is '{}'.", planes);
    }

    if (!IsUndefined(numbrushes))
    {
        spdlog::info("NUMBRUSHES is '{}'.", numbrushes);
    }

    if (!IsUndefined(numpens))
    {
        spdlog::info("NUMPENS is '{}'.", numpens);
    }

    if (!IsUndefined(nummarkers))
    {
        spdlog::info("NUMMARKERS is '{}'.", nummarkers);
    }

    if (!IsUndefined(numfonts))
    {
        spdlog::info("NUMFONTS is '{}'.", numfonts);
    }

    if (!IsUndefined(numcolors))
    {
        spdlog::info("NUMCOLORS is '{}'.", numcolors);
    }

    if (!IsUndefined(pdevicesize))
    {
        spdlog::info("PDEVICESIZE is '{}'.", pdevicesize);
    }

    if (!IsUndefined(curvecaps))
    {
        spdlog::info("CURVECAPS is '{}'.", curvecaps);
    }

    if (!IsUndefined(linecaps))
    {
        spdlog::info("LINECAPS is '{}'.", linecaps);
    }

    if (!IsUndefined(polygonalcaps))
    {
        spdlog::info("POLYGONALCAPS is '{}'.", polygonalcaps);
    }

    if (!IsUndefined(textcaps))
    {
        spdlog::info("TEXTCAPS is '{}'.", textcaps);
    }

    if (!IsUndefined(clipcaps))
    {
        spdlog::info("CLIPCAPS is '{}'.", clipcaps);
    }

    if (!IsUndefined(rastercaps))
    {
        spdlog::info("RASTERCAPS is '{}'.", rastercaps);
    }

    if (!IsUndefined(aspectx))
    {
        spdlog::info("ASPECTX is '{}'.", aspectx);
    }

    if (!IsUndefined(aspecty))
    {
        spdlog::info("ASPECTY is '{}'.", aspecty);
    }

    if (!IsUndefined(aspectxy))
    {
        spdlog::info("ASPECTXY is '{}'.", aspectxy);
    }

    if (!IsUndefined(logpixelsx))
    {
        spdlog::info("LOGPIXELSX is '{}'.", logpixelsx);
    }

    if (!IsUndefined(logpixelsy))
    {
        spdlog::info("LOGPIXELSY is '{}'.", logpixelsy);
    }

    if (!IsUndefined(sizepalette))
    {
        spdlog::info("SIZEPALETTE is '{}'.", sizepalette);
    }

    if (!IsUndefined(numreserved))
    {
        spdlog::info("NUMRESERVED is '{}'.", numreserved);
    }

    if (!IsUndefined(colorres))
    {
        spdlog::info("COLORRES is '{}'.", colorres);
    }

    if (!IsUndefined(physicalwidth))
    {
        spdlog::info("PHYSICALWIDTH is '{}'.", physicalwidth);
    }

    if (!IsUndefined(physicalheight))
    {
        spdlog::info("PHYSICALHEIGHT is '{}'.", physicalheight);
    }

    if (!IsUndefined(physicaloffsetx))
    {
        spdlog::info("PHYSICALOFFSETX is '{}'.", physicaloffsetx);
    }

    if (!IsUndefined(physicaloffsety))
    {
        spdlog::info("PHYSICALOFFSETY is '{}'.", physicaloffsety);
    }

    if (!IsUndefined(scalingfactorx))
    {
        spdlog::info("SCALINGFACTORX is '{}'.", scalingfactorx);
    }

    if (!IsUndefined(scalingfactory))
    {
        spdlog::info("SCALINGFACTORY is '{}'.", scalingfactory);
    }

    if (!IsUndefined(vrefresh))
    {
        spdlog::info("VREFRESH is '{}'.", vrefresh);
    }

    if (!IsUndefined(desktopvertres))
    {
        spdlog::info("DESKTOPVERTRES is '{}'.", desktopvertres);
    }

    if (!IsUndefined(desktophorzres))
    {
        spdlog::info("DESKTOPHORZRES is '{}'.", desktophorzres);
    }

    if (!IsUndefined(bltalignment))
    {
        spdlog::info("BLTALIGNMENT is '{}'.", bltalignment);
    }

    if (!IsUndefined(shadeblendcaps))
    {
        spdlog::info("SHADEBLENDCAPS is '{}'.", shadeblendcaps);
    }

    if (!IsUndefined(colormgmtcaps))
    {
        spdlog::info("COLORMGMTCAPS is '{}'.", colormgmtcaps);
    }
}
