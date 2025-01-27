#include "pch.h"
#include "hooks/hooks.h"
#include "utils/logger.h"
#include "version_info.h"
#include "settings/settings.h"

void Init()
{
    Logger::Init();

    spdlog::info("Win32Hooks {} initialized.", APP_PRODUCT_VERSION_A);

    if (Settings::Load())
    {
        Hooks::Attach();
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Init();
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        Hooks::Detach();
        break;
    }

    return TRUE;
}
