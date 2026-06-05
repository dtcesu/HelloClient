#pragma once
#include <pch.h>

inline int GetRefreshRate() {
    DEVMODE dm = {};
    dm.dmSize = sizeof(dm);
    EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm);

    return dm.dmDisplayFrequency;
}