#include "pch.h"
#include "settings/get_system_metrics_settings.h"

bool SGetSystemMetrics::EnableHook;
int SGetSystemMetrics::sm_arrange;
int SGetSystemMetrics::sm_cleanboot;
int SGetSystemMetrics::sm_cmonitors;
int SGetSystemMetrics::sm_cmousebuttons;
int SGetSystemMetrics::sm_convertibleslatemode;
int SGetSystemMetrics::sm_cxborder;
int SGetSystemMetrics::sm_cxcursor;
int SGetSystemMetrics::sm_cxdlgframe;
int SGetSystemMetrics::sm_cxdoubleclk;
int SGetSystemMetrics::sm_cxdrag;
int SGetSystemMetrics::sm_cxedge;
int SGetSystemMetrics::sm_cxfixedframe;
int SGetSystemMetrics::sm_cxfocusborder;
int SGetSystemMetrics::sm_cxframe;
int SGetSystemMetrics::sm_cxfullscreen;
int SGetSystemMetrics::sm_cxhscroll;
int SGetSystemMetrics::sm_cxhthumb;
int SGetSystemMetrics::sm_cxicon;
int SGetSystemMetrics::sm_cxiconspacing;
int SGetSystemMetrics::sm_cxmaximized;
int SGetSystemMetrics::sm_cxmaxtrack;
int SGetSystemMetrics::sm_cxmenucheck;
int SGetSystemMetrics::sm_cxmenusize;
int SGetSystemMetrics::sm_cxmin;
int SGetSystemMetrics::sm_cxminimized;
int SGetSystemMetrics::sm_cxminspacing;
int SGetSystemMetrics::sm_cxmintrack;
int SGetSystemMetrics::sm_cxpaddedborder;
int SGetSystemMetrics::sm_cxscreen;
int SGetSystemMetrics::sm_cxsize;
int SGetSystemMetrics::sm_cxsizeframe;
int SGetSystemMetrics::sm_cxsmicon;
int SGetSystemMetrics::sm_cxsmsize;
int SGetSystemMetrics::sm_cxvirtualscreen;
int SGetSystemMetrics::sm_cxvscroll;
int SGetSystemMetrics::sm_cyborder;
int SGetSystemMetrics::sm_cycaption;
int SGetSystemMetrics::sm_cycursor;
int SGetSystemMetrics::sm_cydlgframe;
int SGetSystemMetrics::sm_cydoubleclk;
int SGetSystemMetrics::sm_cydrag;
int SGetSystemMetrics::sm_cyedge;
int SGetSystemMetrics::sm_cyfixedframe;
int SGetSystemMetrics::sm_cyfocusborder;
int SGetSystemMetrics::sm_cyframe;
int SGetSystemMetrics::sm_cyfullscreen;
int SGetSystemMetrics::sm_cyhscroll;
int SGetSystemMetrics::sm_cyicon;
int SGetSystemMetrics::sm_cyiconspacing;
int SGetSystemMetrics::sm_cykanjiwindow;
int SGetSystemMetrics::sm_cymaximized;
int SGetSystemMetrics::sm_cymaxtrack;
int SGetSystemMetrics::sm_cymenu;
int SGetSystemMetrics::sm_cymenucheck;
int SGetSystemMetrics::sm_cymenusize;
int SGetSystemMetrics::sm_cymin;
int SGetSystemMetrics::sm_cyminimized;
int SGetSystemMetrics::sm_cyminspacing;
int SGetSystemMetrics::sm_cymintrack;
int SGetSystemMetrics::sm_cyscreen;
int SGetSystemMetrics::sm_cysize;
int SGetSystemMetrics::sm_cysizeframe;
int SGetSystemMetrics::sm_cysmcaption;
int SGetSystemMetrics::sm_cysmicon;
int SGetSystemMetrics::sm_cysmsize;
int SGetSystemMetrics::sm_cyvirtualscreen;
int SGetSystemMetrics::sm_cyvscroll;
int SGetSystemMetrics::sm_cyvthumb;
int SGetSystemMetrics::sm_dbcsenabled;
int SGetSystemMetrics::sm_debug;
int SGetSystemMetrics::sm_digitizer;
int SGetSystemMetrics::sm_immenabled;
int SGetSystemMetrics::sm_maximumtouches;
int SGetSystemMetrics::sm_mediacenter;
int SGetSystemMetrics::sm_menudropalignment;
int SGetSystemMetrics::sm_mideastenabled;
int SGetSystemMetrics::sm_mousepresent;
int SGetSystemMetrics::sm_mousehorizontalwheelpresent;
int SGetSystemMetrics::sm_mousewheelpresent;
int SGetSystemMetrics::sm_network;
int SGetSystemMetrics::sm_penwindows;
int SGetSystemMetrics::sm_remotecontrol;
int SGetSystemMetrics::sm_remotesession;
int SGetSystemMetrics::sm_samedisplayformat;
int SGetSystemMetrics::sm_secure;
int SGetSystemMetrics::sm_serverr2;
int SGetSystemMetrics::sm_showsounds;
int SGetSystemMetrics::sm_shuttingdown;
int SGetSystemMetrics::sm_slowmachine;
int SGetSystemMetrics::sm_starter;
int SGetSystemMetrics::sm_swapbutton;
int SGetSystemMetrics::sm_systemdocked;
int SGetSystemMetrics::sm_tabletpc;
int SGetSystemMetrics::sm_xvirtualscreen;
int SGetSystemMetrics::sm_yvirtualscreen;

void SGetSystemMetrics::Load(toml::table& table)
{
    auto section = table["GetSystemMetrics"];

    EnableHook = section["EnableHook"].value_or(false);

    if (EnableHook)
    {
        sm_arrange = section["SM_ARRANGE"].value_or(UNDEFINED);
        sm_cleanboot = section["SM_CLEANBOOT"].value_or(UNDEFINED);
        sm_cmonitors = section["SM_CMONITORS"].value_or(UNDEFINED);
        sm_cmousebuttons = section["SM_CMOUSEBUTTONS"].value_or(UNDEFINED);
        sm_convertibleslatemode = section["SM_CONVERTIBLESLATEMODE"].value_or(UNDEFINED);
        sm_cxborder = section["SM_CXBORDER"].value_or(UNDEFINED);
        sm_cxcursor = section["SM_CXCURSOR"].value_or(UNDEFINED);
        sm_cxdlgframe = section["SM_CXDLGFRAME"].value_or(UNDEFINED);
        sm_cxdoubleclk = section["SM_CXDOUBLECLK"].value_or(UNDEFINED);
        sm_cxdrag = section["SM_CXDRAG"].value_or(UNDEFINED);
        sm_cxedge = section["SM_CXEDGE"].value_or(UNDEFINED);
        sm_cxfixedframe = section["SM_CXFIXEDFRAME"].value_or(UNDEFINED);
        sm_cxfocusborder = section["SM_CXFOCUSBORDER"].value_or(UNDEFINED);
        sm_cxframe = section["SM_CXFRAME"].value_or(UNDEFINED);
        sm_cxfullscreen = section["SM_CXFULLSCREEN"].value_or(UNDEFINED);
        sm_cxhscroll = section["SM_CXHSCROLL"].value_or(UNDEFINED);
        sm_cxhthumb = section["SM_CXHTHUMB"].value_or(UNDEFINED);
        sm_cxicon = section["SM_CXICON"].value_or(UNDEFINED);
        sm_cxiconspacing = section["SM_CXICONSPACING"].value_or(UNDEFINED);
        sm_cxmaximized = section["SM_CXMAXIMIZED"].value_or(UNDEFINED);
        sm_cxmaxtrack = section["SM_CXMAXTRACK"].value_or(UNDEFINED);
        sm_cxmenucheck = section["SM_CXMENUCHECK"].value_or(UNDEFINED);
        sm_cxmenusize = section["SM_CXMENUSIZE"].value_or(UNDEFINED);
        sm_cxmin = section["SM_CXMIN"].value_or(UNDEFINED);
        sm_cxminimized = section["SM_CXMINIMIZED"].value_or(UNDEFINED);
        sm_cxminspacing = section["SM_CXMINSPACING"].value_or(UNDEFINED);
        sm_cxmintrack = section["SM_CXMINTRACK"].value_or(UNDEFINED);
        sm_cxpaddedborder = section["SM_CXPADDEDBORDER"].value_or(UNDEFINED);
        sm_cxscreen = section["SM_CXSCREEN"].value_or(UNDEFINED);
        sm_cxsize = section["SM_CXSIZE"].value_or(UNDEFINED);
        sm_cxsizeframe = section["SM_CXSIZEFRAME"].value_or(UNDEFINED);
        sm_cxsmicon = section["SM_CXSMICON"].value_or(UNDEFINED);
        sm_cxsmsize = section["SM_CXSMSIZE"].value_or(UNDEFINED);
        sm_cxvirtualscreen = section["SM_CXVIRTUALSCREEN"].value_or(UNDEFINED);
        sm_cxvscroll = section["SM_CXVSCROLL"].value_or(UNDEFINED);
        sm_cyborder = section["SM_CYBORDER"].value_or(UNDEFINED);
        sm_cycaption = section["SM_CYCAPTION"].value_or(UNDEFINED);
        sm_cycursor = section["SM_CYCURSOR"].value_or(UNDEFINED);
        sm_cydlgframe = section["SM_CYDLGFRAME"].value_or(UNDEFINED);
        sm_cydoubleclk = section["SM_CYDOUBLECLK"].value_or(UNDEFINED);
        sm_cydrag = section["SM_CYDRAG"].value_or(UNDEFINED);
        sm_cyedge = section["SM_CYEDGE"].value_or(UNDEFINED);
        sm_cyfixedframe = section["SM_CYFIXEDFRAME"].value_or(UNDEFINED);
        sm_cyfocusborder = section["SM_CYFOCUSBORDER"].value_or(UNDEFINED);
        sm_cyframe = section["SM_CYFRAME"].value_or(UNDEFINED);
        sm_cyfullscreen = section["SM_CYFULLSCREEN"].value_or(UNDEFINED);
        sm_cyhscroll = section["SM_CYHSCROLL"].value_or(UNDEFINED);
        sm_cyicon = section["SM_CYICON"].value_or(UNDEFINED);
        sm_cyiconspacing = section["SM_CYICONSPACING"].value_or(UNDEFINED);
        sm_cykanjiwindow = section["SM_CYKANJIWINDOW"].value_or(UNDEFINED);
        sm_cymaximized = section["SM_CYMAXIMIZED"].value_or(UNDEFINED);
        sm_cymaxtrack = section["SM_CYMAXTRACK"].value_or(UNDEFINED);
        sm_cymenu = section["SM_CYMENU"].value_or(UNDEFINED);
        sm_cymenucheck = section["SM_CYMENUCHECK"].value_or(UNDEFINED);
        sm_cymenusize = section["SM_CYMENUSIZE"].value_or(UNDEFINED);
        sm_cymin = section["SM_CYMIN"].value_or(UNDEFINED);
        sm_cyminimized = section["SM_CYMINIMIZED"].value_or(UNDEFINED);
        sm_cyminspacing = section["SM_CYMINSPACING"].value_or(UNDEFINED);
        sm_cymintrack = section["SM_CYMINTRACK"].value_or(UNDEFINED);
        sm_cyscreen = section["SM_CYSCREEN"].value_or(UNDEFINED);
        sm_cysize = section["SM_CYSIZE"].value_or(UNDEFINED);
        sm_cysizeframe = section["SM_CYSIZEFRAME"].value_or(UNDEFINED);
        sm_cysmcaption = section["SM_CYSMCAPTION"].value_or(UNDEFINED);
        sm_cysmicon = section["SM_CYSMICON"].value_or(UNDEFINED);
        sm_cysmsize = section["SM_CYSMSIZE"].value_or(UNDEFINED);
        sm_cyvirtualscreen = section["SM_CYVIRTUALSCREEN"].value_or(UNDEFINED);
        sm_cyvscroll = section["SM_CYVSCROLL"].value_or(UNDEFINED);
        sm_cyvthumb = section["SM_CYVTHUMB"].value_or(UNDEFINED);
        sm_dbcsenabled = section["SM_DBCSENABLED"].value_or(UNDEFINED);
        sm_debug = section["SM_DEBUG"].value_or(UNDEFINED);
        sm_digitizer = section["SM_DIGITIZER"].value_or(UNDEFINED);
        sm_immenabled = section["SM_IMMENABLED"].value_or(UNDEFINED);
        sm_maximumtouches = section["SM_MAXIMUMTOUCHES"].value_or(UNDEFINED);
        sm_mediacenter = section["SM_MEDIACENTER"].value_or(UNDEFINED);
        sm_menudropalignment = section["SM_MENUDROPALIGNMENT"].value_or(UNDEFINED);
        sm_mideastenabled = section["SM_MIDEASTENABLED"].value_or(UNDEFINED);
        sm_mousepresent = section["SM_MOUSEPRESENT"].value_or(UNDEFINED);
        sm_mousehorizontalwheelpresent = section["SM_MOUSEHORIZONTALWHEELPRESENT"].value_or(UNDEFINED);
        sm_mousewheelpresent = section["SM_MOUSEWHEELPRESENT"].value_or(UNDEFINED);
        sm_network = section["SM_NETWORK"].value_or(UNDEFINED);
        sm_penwindows = section["SM_PENWINDOWS"].value_or(UNDEFINED);
        sm_remotecontrol = section["SM_REMOTECONTROL"].value_or(UNDEFINED);
        sm_remotesession = section["SM_REMOTESESSION"].value_or(UNDEFINED);
        sm_samedisplayformat = section["SM_SAMEDISPLAYFORMAT"].value_or(UNDEFINED);
        sm_secure = section["SM_SECURE"].value_or(UNDEFINED);
        sm_serverr2 = section["SM_SERVERR2"].value_or(UNDEFINED);
        sm_showsounds = section["SM_SHOWSOUNDS"].value_or(UNDEFINED);
        sm_shuttingdown = section["SM_SHUTTINGDOWN"].value_or(UNDEFINED);
        sm_slowmachine = section["SM_SLOWMACHINE"].value_or(UNDEFINED);
        sm_starter = section["SM_STARTER"].value_or(UNDEFINED);
        sm_swapbutton = section["SM_SWAPBUTTON"].value_or(UNDEFINED);
        sm_systemdocked = section["SM_SYSTEMDOCKED"].value_or(UNDEFINED);
        sm_tabletpc = section["SM_TABLETPC"].value_or(UNDEFINED);
        sm_xvirtualscreen = section["SM_XVIRTUALSCREEN"].value_or(UNDEFINED);
        sm_yvirtualscreen = section["SM_YVIRTUALSCREEN"].value_or(UNDEFINED);

        spdlog::info("Describing 'GetSystemMetrics' settings...");
        spdlog::info("-----------------------------------------");
        Describe();
        spdlog::info("-----------------------------------------");
    }
}

bool SGetSystemMetrics::IsUndefined(int& value)
{
    return value == UNDEFINED;
}

void SGetSystemMetrics::Describe()
{
    // YandereDev style

    if (!IsUndefined(sm_arrange))
    {
        spdlog::info("SM_ARRANGE is '{}'.", sm_arrange);
    }

    if (!IsUndefined(sm_cleanboot))
    {
        spdlog::info("SM_CLEANBOOT is '{}'.", sm_cleanboot);
    }

    if (!IsUndefined(sm_cmonitors))
    {
        spdlog::info("SM_CMONITORS is '{}'.", sm_cmonitors);
    }

    if (!IsUndefined(sm_cmousebuttons))
    {
        spdlog::info("SM_CMOUSEBUTTONS is '{}'.", sm_cmousebuttons);
    }

    if (!IsUndefined(sm_convertibleslatemode))
    {
        spdlog::info("SM_CONVERTIBLESLATEMODE is '{}'.", sm_convertibleslatemode);
    }

    if (!IsUndefined(sm_cxborder))
    {
        spdlog::info("SM_CXBORDER is '{}'.", sm_cxborder);
    }

    if (!IsUndefined(sm_cxcursor))
    {
        spdlog::info("SM_CXCURSOR is '{}'.", sm_cxcursor);
    }

    if (!IsUndefined(sm_cxdlgframe))
    {
        spdlog::info("SM_CXDLGFRAME is '{}'.", sm_cxdlgframe);
    }

    if (!IsUndefined(sm_cxdoubleclk))
    {
        spdlog::info("SM_CXDOUBLECLK is '{}'.", sm_cxdoubleclk);
    }

    if (!IsUndefined(sm_cxdrag))
    {
        spdlog::info("SM_CXDRAG is '{}'.", sm_cxdrag);
    }

    if (!IsUndefined(sm_cxedge))
    {
        spdlog::info("SM_CXEDGE is '{}'.", sm_cxedge);
    }

    if (!IsUndefined(sm_cxfixedframe))
    {
        spdlog::info("SM_CXFIXEDFRAME is '{}'.", sm_cxfixedframe);
        spdlog::warn("The value of SM_CXDLGFRAME will be prioritized if set.");
    }

    if (!IsUndefined(sm_cxfocusborder))
    {
        spdlog::info("SM_CXFOCUSBORDER is '{}'.", sm_cxfocusborder);
    }

    if (!IsUndefined(sm_cxframe))
    {
        spdlog::info("SM_CXFRAME is '{}'.", sm_cxframe);
    }

    if (!IsUndefined(sm_cxfullscreen))
    {
        spdlog::info("SM_CXFULLSCREEN is '{}'.", sm_cxfullscreen);
    }

    if (!IsUndefined(sm_cxhscroll))
    {
        spdlog::info("SM_CXHSCROLL is '{}'.", sm_cxhscroll);
    }

    if (!IsUndefined(sm_cxhthumb))
    {
        spdlog::info("SM_CXHTHUMB is '{}'.", sm_cxhthumb);
    }

    if (!IsUndefined(sm_cxicon))
    {
        spdlog::info("SM_CXICON is '{}'.", sm_cxicon);
    }

    if (!IsUndefined(sm_cxiconspacing))
    {
        spdlog::info("SM_CXICONSPACING is '{}'.", sm_cxiconspacing);
    }

    if (!IsUndefined(sm_cxmaximized))
    {
        spdlog::info("SM_CXMAXIMIZED is '{}'.", sm_cxmaximized);
    }

    if (!IsUndefined(sm_cxmaxtrack))
    {
        spdlog::info("SM_CXMAXTRACK is '{}'.", sm_cxmaxtrack);
    }

    if (!IsUndefined(sm_cxmenucheck))
    {
        spdlog::info("SM_CXMENUCHECK is '{}'.", sm_cxmenucheck);
    }

    if (!IsUndefined(sm_cxmenusize))
    {
        spdlog::info("SM_CXMENUSIZE is '{}'.", sm_cxmenusize);
    }

    if (!IsUndefined(sm_cxmin))
    {
        spdlog::info("SM_CXMIN is '{}'.", sm_cxmin);
    }

    if (!IsUndefined(sm_cxminimized))
    {
        spdlog::info("SM_CXMINIMIZED is '{}'.", sm_cxminimized);
    }

    if (!IsUndefined(sm_cxminspacing))
    {
        spdlog::info("SM_CXMINSPACING is '{}'.", sm_cxminspacing);
    }

    if (!IsUndefined(sm_cxmintrack))
    {
        spdlog::info("SM_CXMINTRACK is '{}'.", sm_cxmintrack);
    }

    if (!IsUndefined(sm_cxpaddedborder))
    {
        spdlog::info("SM_CXPADDEDBORDER is '{}'.", sm_cxpaddedborder);
    }

    if (!IsUndefined(sm_cxscreen))
    {
        spdlog::info("SM_CXSCREEN is '{}'.", sm_cxscreen);
    }

    if (!IsUndefined(sm_cxsize))
    {
        spdlog::info("SM_CXSIZE is '{}'.", sm_cxsize);
    }

    if (!IsUndefined(sm_cxsizeframe))
    {
        spdlog::info("SM_CXSIZEFRAME is '{}'.", sm_cxsizeframe);
        spdlog::warn("The value of SM_CXFRAME will be prioritized if set.");
    }

    if (!IsUndefined(sm_cxsmicon))
    {
        spdlog::info("SM_CXSMICON is '{}'.", sm_cxsmicon);
    }

    if (!IsUndefined(sm_cxsmsize))
    {
        spdlog::info("SM_CXSMSIZE is '{}'.", sm_cxsmsize);
    }

    if (!IsUndefined(sm_cxvirtualscreen))
    {
        spdlog::info("SM_CXVIRTUALSCREEN is '{}'.", sm_cxvirtualscreen);
    }

    if (!IsUndefined(sm_cxvscroll))
    {
        spdlog::info("SM_CXVSCROLL is '{}'.", sm_cxvscroll);
    }

    if (!IsUndefined(sm_cyborder))
    {
        spdlog::info("SM_CYBORDER is '{}'.", sm_cyborder);
    }

    if (!IsUndefined(sm_cycaption))
    {
        spdlog::info("SM_CYCAPTION is '{}'.", sm_cycaption);
    }

    if (!IsUndefined(sm_cycursor))
    {
        spdlog::info("SM_CYCURSOR is '{}'.", sm_cycursor);
    }

    if (!IsUndefined(sm_cydlgframe))
    {
        spdlog::info("SM_CYDLGFRAME is '{}'.", sm_cydlgframe);
    }

    if (!IsUndefined(sm_cydoubleclk))
    {
        spdlog::info("SM_CYDOUBLECLK is '{}'.", sm_cydoubleclk);
    }

    if (!IsUndefined(sm_cydrag))
    {
        spdlog::info("SM_CYDRAG is '{}'.", sm_cydrag);
    }

    if (!IsUndefined(sm_cyedge))
    {
        spdlog::info("SM_CYEDGE is '{}'.", sm_cyedge);
    }

    if (!IsUndefined(sm_cyfixedframe))
    {
        spdlog::info("SM_CYFIXEDFRAME is '{}'.", sm_cyfixedframe);
        spdlog::warn("The value of SM_CYDLGFRAME will be prioritized if set.");
    }

    if (!IsUndefined(sm_cyfocusborder))
    {
        spdlog::info("SM_CYFOCUSBORDER is '{}'.", sm_cyfocusborder);
    }

    if (!IsUndefined(sm_cyframe))
    {
        spdlog::info("SM_CYFRAME is '{}'.", sm_cyframe);
    }

    if (!IsUndefined(sm_cyfullscreen))
    {
        spdlog::info("SM_CYFULLSCREEN is '{}'.", sm_cyfullscreen);
    }

    if (!IsUndefined(sm_cyhscroll))
    {
        spdlog::info("SM_CYHSCROLL is '{}'.", sm_cyhscroll);
    }

    if (!IsUndefined(sm_cyicon))
    {
        spdlog::info("SM_CYICON is '{}'.", sm_cyicon);
    }

    if (!IsUndefined(sm_cyiconspacing))
    {
        spdlog::info("SM_CYICONSPACING is '{}'.", sm_cyiconspacing);
    }

    if (!IsUndefined(sm_cykanjiwindow))
    {
        spdlog::info("SM_CYKANJIWINDOW is '{}'.", sm_cykanjiwindow);
    }

    if (!IsUndefined(sm_cymaximized))
    {
        spdlog::info("SM_CYMAXIMIZED is '{}'.", sm_cymaximized);
    }

    if (!IsUndefined(sm_cymaxtrack))
    {
        spdlog::info("SM_CYMAXTRACK is '{}'.", sm_cymaxtrack);
    }

    if (!IsUndefined(sm_cymenu))
    {
        spdlog::info("SM_CYMENU is '{}'.", sm_cymenu);
    }

    if (!IsUndefined(sm_cymenucheck))
    {
        spdlog::info("SM_CYMENUCHECK is '{}'.", sm_cymenucheck);
    }

    if (!IsUndefined(sm_cymenusize))
    {
        spdlog::info("SM_CYMENUSIZE is '{}'.", sm_cymenusize);
    }

    if (!IsUndefined(sm_cymin))
    {
        spdlog::info("SM_CYMIN is '{}'.", sm_cymin);
    }

    if (!IsUndefined(sm_cyminimized))
    {
        spdlog::info("SM_CYMINIMIZED is '{}'.", sm_cyminimized);
    }

    if (!IsUndefined(sm_cyminspacing))
    {
        spdlog::info("SM_CYMINSPACING is '{}'.", sm_cyminspacing);
    }

    if (!IsUndefined(sm_cymintrack))
    {
        spdlog::info("SM_CYMINTRACK is '{}'.", sm_cymintrack);
    }

    if (!IsUndefined(sm_cyscreen))
    {
        spdlog::info("SM_CYSCREEN is '{}'.", sm_cyscreen);
    }

    if (!IsUndefined(sm_cysize))
    {
        spdlog::info("SM_CYSIZE is '{}'.", sm_cysize);
    }

    if (!IsUndefined(sm_cysizeframe))
    {
        spdlog::info("SM_CYSIZEFRAME is '{}'.", sm_cysizeframe);
        spdlog::warn("The value of SM_CYFRAME will be prioritized if set.");
    }

    if (!IsUndefined(sm_cysmcaption))
    {
        spdlog::info("SM_CYSMCAPTION is '{}'.", sm_cysmcaption);
    }

    if (!IsUndefined(sm_cysmicon))
    {
        spdlog::info("SM_CYSMICON is '{}'.", sm_cysmicon);
    }

    if (!IsUndefined(sm_cysmsize))
    {
        spdlog::info("SM_CYSMSIZE is '{}'.", sm_cysmsize);
    }

    if (!IsUndefined(sm_cyvirtualscreen))
    {
        spdlog::info("SM_CYVIRTUALSCREEN is '{}'.", sm_cyvirtualscreen);
    }

    if (!IsUndefined(sm_cyvscroll))
    {
        spdlog::info("SM_CYVSCROLL is '{}'.", sm_cyvscroll);
    }

    if (!IsUndefined(sm_cyvthumb))
    {
        spdlog::info("SM_CYVTHUMB is '{}'.", sm_cyvthumb);
    }

    if (!IsUndefined(sm_dbcsenabled))
    {
        spdlog::info("SM_DBCSENABLED is '{}'.", sm_dbcsenabled);
    }

    if (!IsUndefined(sm_debug))
    {
        spdlog::info("SM_DEBUG is '{}'.", sm_debug);
    }

    if (!IsUndefined(sm_digitizer))
    {
        spdlog::info("SM_DIGITIZER is '{}'.", sm_digitizer);
    }

    if (!IsUndefined(sm_immenabled))
    {
        spdlog::info("SM_IMMENABLED is '{}'.", sm_immenabled);
    }

    if (!IsUndefined(sm_maximumtouches))
    {
        spdlog::info("SM_MAXIMUMTOUCHES is '{}'.", sm_maximumtouches);
    }

    if (!IsUndefined(sm_mediacenter))
    {
        spdlog::info("SM_MEDIACENTER is '{}'.", sm_mediacenter);
    }

    if (!IsUndefined(sm_menudropalignment))
    {
        spdlog::info("SM_MENUDROPALIGNMENT is '{}'.", sm_menudropalignment);
    }

    if (!IsUndefined(sm_mideastenabled))
    {
        spdlog::info("SM_MIDEASTENABLED is '{}'.", sm_mideastenabled);
    }

    if (!IsUndefined(sm_mousepresent))
    {
        spdlog::info("SM_MOUSEPRESENT is '{}'.", sm_mousepresent);
    }

    if (!IsUndefined(sm_mousehorizontalwheelpresent))
    {
        spdlog::info("SM_MOUSEHORIZONTALWHEELPRESENT is '{}'.", sm_mousehorizontalwheelpresent);
    }

    if (!IsUndefined(sm_mousewheelpresent))
    {
        spdlog::info("SM_MOUSEWHEELPRESENT is '{}'.", sm_mousewheelpresent);
    }

    if (!IsUndefined(sm_network))
    {
        spdlog::info("SM_NETWORK is '{}'.", sm_network);
    }

    if (!IsUndefined(sm_penwindows))
    {
        spdlog::info("SM_PENWINDOWS is '{}'.", sm_penwindows);
    }

    if (!IsUndefined(sm_remotecontrol))
    {
        spdlog::info("SM_REMOTECONTROL is '{}'.", sm_remotecontrol);
    }

    if (!IsUndefined(sm_remotesession))
    {
        spdlog::info("SM_REMOTESESSION is '{}'.", sm_remotesession);
    }

    if (!IsUndefined(sm_samedisplayformat))
    {
        spdlog::info("SM_SAMEDISPLAYFORMAT is '{}'.", sm_samedisplayformat);
    }

    if (!IsUndefined(sm_secure))
    {
        spdlog::info("SM_SECURE is '{}'.", sm_secure);
    }

    if (!IsUndefined(sm_serverr2))
    {
        spdlog::info("SM_SERVERR2 is '{}'.", sm_serverr2);
    }

    if (!IsUndefined(sm_showsounds))
    {
        spdlog::info("SM_SHOWSOUNDS is '{}'.", sm_showsounds);
    }

    if (!IsUndefined(sm_shuttingdown))
    {
        spdlog::info("SM_SHUTTINGDOWN is '{}'.", sm_shuttingdown);
    }

    if (!IsUndefined(sm_slowmachine))
    {
        spdlog::info("SM_SLOWMACHINE is '{}'.", sm_slowmachine);
    }

    if (!IsUndefined(sm_starter))
    {
        spdlog::info("SM_STARTER is '{}'.", sm_starter);
    }

    if (!IsUndefined(sm_swapbutton))
    {
        spdlog::info("SM_SWAPBUTTON is '{}'.", sm_swapbutton);
    }

    if (!IsUndefined(sm_systemdocked))
    {
        spdlog::info("SM_SYSTEMDOCKED is '{}'.", sm_systemdocked);
    }

    if (!IsUndefined(sm_tabletpc))
    {
        spdlog::info("SM_TABLETPC is '{}'.", sm_tabletpc);
    }

    if (!IsUndefined(sm_xvirtualscreen))
    {
        spdlog::info("SM_XVIRTUALSCREEN is '{}'.", sm_xvirtualscreen);
    }

    if (!IsUndefined(sm_yvirtualscreen))
    {
        spdlog::info("SM_YVIRTUALSCREEN is '{}'.", sm_yvirtualscreen);
    }
}
