#pragma once

namespace Settings
{
    class SetWindowPos
    {
    public:
        static bool EnableHook;
        static bool DisableAlwaysOnTop;

        static void Load(toml::table& table);

    private:
        static void Describe();
    };
}
