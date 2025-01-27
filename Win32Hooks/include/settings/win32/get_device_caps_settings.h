#pragma once

namespace Settings
{
    class GetDeviceCaps
    {
    public:
        static const int UNDEFINED = -393939;

        static bool EnableHook;

        static int driverversion;
        static int technology;
        static int horzsize;
        static int vertsize;
        static int horzres;
        static int vertres;
        static int bitspixel;
        static int planes;
        static int numbrushes;
        static int numpens;
        static int nummarkers;
        static int numfonts;
        static int numcolors;
        static int pdevicesize;
        static int curvecaps;
        static int linecaps;
        static int polygonalcaps;
        static int textcaps;
        static int clipcaps;
        static int rastercaps;
        static int aspectx;
        static int aspecty;
        static int aspectxy;
        static int logpixelsx;
        static int logpixelsy;
        static int sizepalette;
        static int numreserved;
        static int colorres;
        static int physicalwidth;
        static int physicalheight;
        static int physicaloffsetx;
        static int physicaloffsety;
        static int scalingfactorx;
        static int scalingfactory;
        static int vrefresh;
        static int desktopvertres;
        static int desktophorzres;
        static int bltalignment;
        static int shadeblendcaps;
        static int colormgmtcaps;

        static void Load(toml::table& table);

        static bool IsUndefined(int& value);

    private:
        static void Describe();
    };
}
