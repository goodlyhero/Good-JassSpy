#include <Windows.h>
#include <format>

#include "Consts.h"
#include "DllInfo.h"

ptr_t pGame;
ptr_t pThisLib;
size_t gameVersion;

static const size_t DllSearchTimeout = 3000;

ptr_t SearchForModule(std::string s)
{
	ptr_t result = (ptr_t)GetModuleHandle(s.c_str());
	size_t tries = 0;
	while ((result == nullptr) && (tries < DllSearchTimeout))
	{
		Sleep(1);
		tries++;
		result = (ptr_t)GetModuleHandle(s.c_str());
	}
	return result;
}

void InitConsts()
{
	pGame = SearchForModule("Game.dll");
	gameVersion = DLLVersion("Game.dll");
}