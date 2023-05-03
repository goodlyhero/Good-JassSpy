#pragma once
#include "type_allias.h"
#include <string>

unsigned int ObjectToHandleId(ptr_t address);
std::string GetIdFromPtr(ptr_t ptr);


#define GAMEFLAG_OK 1
#define GAMEFLAG_LOADING 2
#define GAMEFLAG_INGAME 4
#define GAMEFLAG_SINGLEPLAYER 8 //TODO?
#define GAMEFLAG_MULTYPLAYER 16 //TODO?
#define GAMEFLAG_REPLAY 32		//TODO?

unsigned int GetGameType();