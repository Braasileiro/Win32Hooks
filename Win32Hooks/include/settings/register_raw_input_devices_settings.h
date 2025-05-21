#pragma once

namespace Settings
{
    class RegisterRawInputDevices
    {
    public:
        static bool EnableHook;
        static bool RemoveNoHotkeysFlag;

        static void Load(toml::table& table);

    private:
        static void Describe();
    };
}
