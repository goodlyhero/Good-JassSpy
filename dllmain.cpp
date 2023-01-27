// dllmain.cpp : Определяет точку входа для приложения DLL.
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <string_view>
#include <format>


#include "Memory.h"
#include "Consts.h"
#include "DllInfo.h"
#include "Warcraft Consts.h"
#include "Simple_ncall_hook.h"
#include "Jass_call_hook.h"
#include "simple_ret_hook.h"
#include "IniReader.h"
#include "SimpleOrderHook.h"
#include "UnitPositionHook.h"
#include "AgentPresenceHook.h"

void OpenConsole()
{
    bool allocated = AllocConsole();
    HANDLE console = GetConsoleWindow();
    SetStdHandle(STD_OUTPUT_HANDLE, console);
}

void InitConsole()
{
    if (AllocConsole())
    {
        FILE* fp = nullptr;
        freopen_s(&fp, "CONIN$", "r", stdin);
        freopen_s(&fp, "CONOUT$", "w", stdout);
        freopen_s(&fp, "CONOUT$", "w", stderr);
        std::ios::sync_with_stdio(true);

        // Clear the error state for each of the C++ standard streams.
        std::wcout.clear();
        std::cout.clear();
        std::wcerr.clear();
        std::cerr.clear();
        std::wcin.clear();
        std::cin.clear();

    }
}

DWORD WINAPI TimedInit(void* u)
{
    using namespace std::chrono_literals;
    Sleep(1);
    //InitConsole();
    InitConsts();
    if (pGame == 0)
    {
        MessageBox(NULL, "Unable to find game.dll, detaching", "Error", MB_OK);
        FreeLibraryAndExitThread((HMODULE)pThisLib, 0);
        return NULL;
    }
    if (gameVersion != 6401)
    {
        {
            auto result = std::format(
                "Good JassSpy injected,\nWC3 version incorrect: {:d}\nmust be 6401\nGame.dll: {:X}",
                gameVersion,
                (size_t)pGame);
            MessageBox(NULL, result.c_str(), "ERROR", MB_OK);
        }
        FreeLibraryAndExitThread((HMODULE)pThisLib, 0);
        
    }
    else
    {
        
        auto result = std::format(
            "Good JassSpy Injected!\nGame.dll: {:X}\nGame Version: {:d}",
            (std::uint32_t)pGame, gameVersion);
        std::cout << result << std::endl;
    }
    InitWarcraftConsts();
    auto settings = INIReader::INIReader("goodjasspy.ini");
    if (settings.ParseError() == 0)
    {
        if (settings.GetBoolean("jasspy", "console", false))
        {
            InitConsole();
            std::cout << "Console Initialized" << std::endl;
        }
        if(settings.GetBoolean("jasspy", "hookjvm", false))
        {
            std::cout << "Initializing jvm hook" << std::endl;
            InitSimpleHook();
            InitJcallHook();
            Init_jvm_ret_hook();
        }
        if(settings.GetBoolean("jasspy", "hookorderinstant", false))
        {
            std::cout << "Initializing immediate order hook" << std::endl;
            InitImmediateOrderHook();
        }
        if (settings.GetBoolean("jasspy", "hookorderpoint", false))
        {
            std::cout << "Initializing point order hook" << std::endl;
            InitPointOrderHook();
        }
        if (settings.GetBoolean("jasspy", "hookpos", false))
        {
            std::cout << "Initializing unit pos hook" << std::endl;
            InitUnitPosHook();
        }
        if (settings.GetBoolean("jasspy", "hookpresence", false))
        {
            std::cout << "Initializing presence hook" << std::endl;
            InitAgentPresenceHook();
        }
    }
    else
    {
        std::cout << "Unable to find out settings file. initializing jvm hook only" << std::endl;
        InitSimpleHook();
        InitJcallHook();
        Init_jvm_ret_hook();
    }
    return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        pThisLib = (ptr_t )hModule;
        CreateThread(NULL, 4000, TimedInit, NULL, NULL, NULL);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

