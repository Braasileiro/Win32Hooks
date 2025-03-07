#include "pch.h"
#include "settings/win32/set_window_pos_settings.h"

using namespace Settings;

bool SetWindowPos::EnableHook;
bool SetWindowPos::DisableAlwaysOnTop;

void SetWindowPos::Load(toml::table& table)
{
    auto section = table["SetWindowPos"];

    EnableHook = section["EnableHook"].value_or(false);

    if (EnableHook)
    {
        DisableAlwaysOnTop = section["DisableAlwaysOnTop"].value_or(false);

        spdlog::info("Describing 'SetWindowPos' settings...");
        spdlog::info("-------------------------------------");
        Describe();
        spdlog::info("-------------------------------------");
    }
}

void SetWindowPos::Describe()
{
    spdlog::info("DisableAlwaysOnTop is '{}'.", DisableAlwaysOnTop);
}
