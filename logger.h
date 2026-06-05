#pragma once
#include "pch.h"
#include <string>
#include <windows.h>

enum class LogLevel {
    Debug,
    Warn,
    Error
};

inline void InternalLog(LogLevel level, const std::string& text)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    WORD color = 7;
    const char* prefix = "(hmod) ";

    switch (level)
    {
    case LogLevel::Debug:
        prefix = "(debg) ";
        break;
    case LogLevel::Warn:
        color = 14;
        prefix = "(warn) ";
        break;
    case LogLevel::Error:
        color = 12;
        prefix = "(crit) ";
        break;
    }

    DWORD written = 0;
    std::string logmessage = text + "\n";

    SetConsoleTextAttribute(hConsole, color);
    WriteConsoleA(hConsole, prefix, (DWORD)strlen(prefix), &written, nullptr);

    SetConsoleTextAttribute(hConsole, 8);
    WriteConsoleA(hConsole, ">> ", 3, &written, nullptr);

    SetConsoleTextAttribute(hConsole, 15);
    WriteConsoleA(hConsole, logmessage.c_str(), (DWORD)logmessage.size(), &written, nullptr);
}

#define LOG_DEBUG(x) InternalLog(LogLevel::Debug, x)
#define LOG_WARN(x)  InternalLog(LogLevel::Warn, x)
#define LOG_ERROR(x) InternalLog(LogLevel::Error, x)