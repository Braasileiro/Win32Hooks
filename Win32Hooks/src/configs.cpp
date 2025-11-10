#include "pch.h"
#include "configs.h"
#include "settings/get_device_caps_settings.h"
#include "settings/get_system_metrics_settings.h"
#include "settings/register_raw_input_devices_settings.h"
#include "settings/set_window_pos_settings.h"

bool Configs::Load()
{
    toml::table table;

    try
    {
        table = toml::parse_file("Win32Hooks.toml");
    }
    catch (std::exception& e)
    {
        spdlog::error(e.what());

        spdlog::warn("Failed to load settings. Hooks will not be applied.");

        return false;
    }

    spdlog::info("Settings loaded.");

    SGetDeviceCaps::Load(table);
    SGetSystemMetrics::Load(table);
    SRegisterRawInputDevices::Load(table);
    SSetWindowPos::Load(table);

    return true;
}
