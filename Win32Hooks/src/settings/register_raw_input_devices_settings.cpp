#include "pch.h"
#include "settings/register_raw_input_devices_settings.h"

using namespace Settings;

bool RegisterRawInputDevices::EnableHook;
bool RegisterRawInputDevices::UnlockWindowsKey;

void RegisterRawInputDevices::Load(toml::table& table)
{
    auto section = table["RegisterRawInputDevices"];

    EnableHook = section["EnableHook"].value_or(false);

    if (EnableHook)
    {
        UnlockWindowsKey = section["UnlockWindowsKey"].value_or(false);

        spdlog::info("Describing 'RegisterRawInputDevices' settings...");
        spdlog::info("------------------------------------------------");
        Describe();
        spdlog::info("------------------------------------------------");
    }
}

void RegisterRawInputDevices::Describe()
{
    spdlog::info("UnlockWindowsKey is '{}'.", UnlockWindowsKey);
}
