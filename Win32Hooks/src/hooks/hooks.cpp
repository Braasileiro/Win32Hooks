#include "pch.h"
#include "hooks/hooks.h"
#include "hooks/win32/get_device_caps_hook.h"
#include "hooks/win32/get_system_metrics_hook.h"
#include "hooks/win32/register_raw_input_devices_hook.h"

void Hooks::Attach()
{
    spdlog::info("Attaching hooks...");

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    GetDeviceCapsHook::Attach();
    GetSystemMetricsHook::Attach();
    RegisterRawInputDevicesHook::Attach();

    Commit();
}

void Hooks::Detach()
{
    spdlog::info("Detaching hooks...");

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    
    GetDeviceCapsHook::Detach();
    GetSystemMetricsHook::Detach();
    RegisterRawInputDevicesHook::Detach();

    Commit();
}

bool Hooks::Commit()
{
    auto result = DetourTransactionCommit();

    switch (result)
    {
    case NO_ERROR:
        return true;

    case ERROR_INVALID_DATA:
        spdlog::error("DetourTransactionCommit returned ERROR_INVALID_DATA.");
        return false;

    case ERROR_INVALID_OPERATION:
        spdlog::error("DetourTransactionCommit returned ERROR_INVALID_OPERATION.");
        return false;

    default:
        spdlog::error("DetourTransactionCommit returned an unknown error.");
        return false;
    }
}
