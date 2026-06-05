// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

DWORD Entrypoint(LPVOID)
{
    if (options::bConsole)
    {
        AllocConsole();
        SetConsoleTitleA("HelloMod | An proprietary mod for Hello Neighbor");
        system("mode con: cols=100 lines=20");
    }

    LOG_DEBUG("forcing display settings to windowed, 1920x1080.");
    LOG_DEBUG("monitor refresh-rate: " + std::to_string(GetRefreshRate()));

    hooks::init();

    while (UEngine::GetEngine() == NULL)
        Sleep(10);

    while (UEngine::GetEngine()->GameViewport == NULL)
        Sleep(10);

    if (auto GEngine = UEngine::GetEngine())
    {
        LOG_DEBUG("found gengine.");
        GEngine->bUseFixedFrameRate = true;
        GEngine->FixedFrameRate = GetRefreshRate();

        SDK::UObject *NewObject = UGameplayStatics::SpawnObject(GEngine->ConsoleClass, GEngine->GameViewport);
        GEngine->GameViewport->ViewportConsole = static_cast<SDK::UConsole *>(NewObject);
        LOG_DEBUG("spawned console.");

        auto GameUserSettings = GEngine->GameUserSettings;
        GameUserSettings->SetViewDistanceQuality(3);
        GameUserSettings->SetShadowQuality(3);
        GameUserSettings->SetTextureQuality(3);
        GameUserSettings->SetPostProcessingQuality(3);
        GameUserSettings->SetVisualEffectQuality(3);
        GameUserSettings->SetFoliageQuality(3);
        GameUserSettings->ApplySettings(true);

        LOG_DEBUG("applied graphical fixes.");
        // LOG_DEBUG("actors: " + std::to_string(Actors.Num()));
    }

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, Entrypoint, 0, 0, 0);
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
