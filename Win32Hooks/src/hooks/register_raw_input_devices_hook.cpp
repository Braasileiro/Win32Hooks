#include "pch.h"
#include "hooks/register_raw_input_devices_hook.h"
#include "settings/register_raw_input_devices_settings.h"

// States
int kNotified = 0;

// https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registerrawinputdevices
static BOOL(WINAPI* _RegisterRawInputDevices)(PCRAWINPUTDEVICE pRawInputDevices, UINT uiNumDevices, UINT cbSize) = RegisterRawInputDevices;

BOOL WINAPI HK_RegisterRawInputDevices(PCRAWINPUTDEVICE pRawInputDevices, UINT uiNumDevices, UINT cbSize)
{
    if (cbSize != sizeof(RAWINPUTDEVICE))
    {
        spdlog::warn("RegisterRawInputDevices struct size not matches. Running with the original parameters.");

        return _RegisterRawInputDevices(pRawInputDevices, uiNumDevices, cbSize);
    }
    else if (!Settings::RegisterRawInputDevices::RemoveNoHotkeysFlag)
    {
        return _RegisterRawInputDevices(pRawInputDevices, uiNumDevices, cbSize);
    }
    else
    {
        std::vector<RAWINPUTDEVICE> devices;

        for (size_t i = 0; i < uiNumDevices; i++)
        {
            auto current = pRawInputDevices[i];

            // Check if the device has a RIDEV_NOHOTKEYS flag
            if (current.dwFlags & RIDEV_NOHOTKEYS)
            {
                /*
                * Removes the RIDEV_NOHOTKEYS flag.
                * This reactivates the hotkeys defined by the application (system-wide), including the Windows key, without the risk of double input.
                * The RIDEV_NOLEGACY approach was previously flawed in some games such as Doom (2016).
                * This approach is more secure and stable, and does not alter the other flags that are set for the device.
                */
                current.dwFlags ^= RIDEV_NOHOTKEYS;

                /*
                 * Maximum of 5 notifications.
                 * Some applications frequently unregister and register RawInput devices.
                 */
                if (kNotified < 5)
                {
                    spdlog::info("The device has RIDEV_NOHOTKEYS flag. The flag has been removed.");

                    kNotified += 1;

                    if (kNotified == 5)
                    {
                        spdlog::info("RegisterRawInputDevices flag override messages on devices will no longer be notified.");
                    }
                }
            }

            devices.push_back(current);
        }

        return _RegisterRawInputDevices(
            devices.data(),
            static_cast<UINT>(devices.size()),
            cbSize
        );
    }
}

void RegisterRawInputDevicesHook::Attach()
{
    if (Settings::RegisterRawInputDevices::EnableHook)
    {
        DetourAttach(&(PVOID&)_RegisterRawInputDevices, HK_RegisterRawInputDevices);

        spdlog::info("RegisterRawInputDevices hook attached.");
    }
}

void RegisterRawInputDevicesHook::Detach()
{
    if (Settings::RegisterRawInputDevices::EnableHook)
    {
        DetourDetach(&(PVOID&)_RegisterRawInputDevices, HK_RegisterRawInputDevices);

        spdlog::info("RegisterRawInputDevices hook detached.");
    }
}
