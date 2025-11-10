#include "pch.h"
#include "settings/register_raw_input_devices_settings.h"

bool SRegisterRawInputDevices::EnableHook;
bool SRegisterRawInputDevices::RemoveNoHotkeysFlag;

void SRegisterRawInputDevices::Load(toml::table& table)
{
    auto section = table["RegisterRawInputDevices"];

    EnableHook = section["EnableHook"].value_or(false);

    if (EnableHook)
    {
        RemoveNoHotkeysFlag = section["RemoveNoHotkeysFlag"].value_or(false);

        spdlog::info("Describing 'RegisterRawInputDevices' settings...");
        spdlog::info("------------------------------------------------");
        Describe();
        spdlog::info("------------------------------------------------");
    }
}

void SRegisterRawInputDevices::Describe()
{
    spdlog::info("RemoveNoHotkeysFlag is '{}'.", RemoveNoHotkeysFlag);
}
