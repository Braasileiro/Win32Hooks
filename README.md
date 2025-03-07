# Win32Hooks
Hook some Win32 API functions at runtime.

# Usage
This program has been designed so that it is **injected** into the application process. You can use any **DLL injector**, here are some examples.

### [Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader)
A powerful multipurpose injector that's easy to configure.

Download the latest version taking into account whether the application is `x86` or `x64`, rename the Ultimate ASI Loader DLL to something that the application loads, most games use `dinput8.dll`. Place the `Win32Hooks(32|64).dll` inside the `root directory of the application` or in the `scripts`, `plugins`, or `update` folders.

I usually use the folder `plugins`, you should probably create it the first time you set it up in your application.

The Ultimate ASI Loader only reads files with the `.asi` extension, but these are only .dll files with the extension renamed.

Rename the extension of `Win32Hooks(32|64).dll` to `Win32Hooks(32|64).asi`.

### [SpecialK](https://github.com/SpecialKO/SpecialK)
You can use SpecialK [Custom Plugin](https://wiki.special-k.info/en/SpecialK/Tools#custom-plugin) feature to load the DLL along with it. I recommend setting `When` configuration to `Early`.

### Configuration
Open the `Win32Hooks.toml` file and set any parameters you want on the supported functions.

> [!NOTE]
> The file `Win32Hooks.toml` must be in the same folder as `Win32Hooks(32|64).(dll|asi)`.

# Supported Functions
* [GetDeviceCaps](https://learn.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-getdevicecaps)
* [GetSystemMetrics](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics)
* [RegisterRawInputDevices](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registerrawinputdevices) (Unlock Windows key)
* [SetWindowPos](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowpos) (Disable always on top)

# Notes
This project is the merging of my current hooks into one place, development will take place only here from now on.

Here are the original archived projects.

* [GetSystemMetricsHook](https://github.com/Braasileiro/GetSystemMetricsHook)
* [NoHotkeysFlagDisabler](https://github.com/Braasileiro/NoHotkeysFlagDisabler)

I don't intend to add other features if they aren't related to the functions used in the hooks, so I'll leave the issues closed.

I hope this helps someone. :sob:
