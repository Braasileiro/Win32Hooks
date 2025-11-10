#include "pch.h"
#include "settings/set_window_pos_settings.h"

bool SSetWindowPos::EnableHook;
bool SSetWindowPos::DisableAlwaysOnTop;

void SSetWindowPos::Load(toml::table& table)
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

void SSetWindowPos::Describe()
{
    spdlog::info("DisableAlwaysOnTop is '{}'.", DisableAlwaysOnTop);
}
