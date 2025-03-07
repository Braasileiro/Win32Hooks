#pragma once

namespace GetSystemMetricsHook
{
    void Attach();

    void Detach();

    int GetValueByIndex(int& nIndex);
};
