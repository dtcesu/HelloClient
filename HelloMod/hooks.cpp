#include "pch.h"

TCHAR* hooks::FCommandLineGet() {
    static std::wstring modified;

    TCHAR* Original = FCommandLineGetOG();

    modified = Original;
    modified += L"-windowed -ResX=1920 -ResY=1080";

    return (TCHAR*)modified.c_str();
}

void hooks::init() {
    MH_Initialize();

    LOG_DEBUG("hooking FCommandLine::Get().");
    MH_CreateHook((LPVOID*)offsets::FCommandLineGet, FCommandLineGet, (LPVOID*)&FCommandLineGetOG);
    MH_EnableHook((LPVOID*)offsets::FCommandLineGet);
}