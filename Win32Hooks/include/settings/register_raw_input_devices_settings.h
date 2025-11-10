#pragma once

class SRegisterRawInputDevices
{
public:
    static bool EnableHook;
    static bool RemoveNoHotkeysFlag;

    static void Load(toml::table& table);

private:
    static void Describe();
};
