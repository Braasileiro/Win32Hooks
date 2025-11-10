#include "pch.h"
#include "loader.h"
#include "configs.h"
#include "version_info.h"
#include "utils/logger.hpp"

void Init()
{
    Logger::Init("Win32Hooks.log");

    spdlog::info("Win32Hooks {} initialized.", APP_PRODUCT_VERSION_A);

    if (Configs::Load())
    {
        Loader::Attach();
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);

        Init();
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        Loader::Detach();
        break;
    }

    return TRUE;
}
