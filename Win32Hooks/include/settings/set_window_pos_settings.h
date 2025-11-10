#pragma once

class SSetWindowPos
{
public:
    static bool EnableHook;
    static bool DisableAlwaysOnTop;

    static void Load(toml::table& table);

private:
    static void Describe();
};
