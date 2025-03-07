#include "pch.h"
#include "settings/settings.h"
#include "settings/get_device_caps_settings.h"
#include "settings/get_system_metrics_settings.h"
#include "settings/register_raw_input_devices_settings.h"

bool Settings::Load()
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

    Settings::GetDeviceCaps::Load(table);
    Settings::GetSystemMetrics::Load(table);
    Settings::RegisterRawInputDevices::Load(table);

    return true;
}
