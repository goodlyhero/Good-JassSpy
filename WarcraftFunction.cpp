#include "Calls.h"
#include "Memory.h"
#include "type_allias.h"
#include "Warcraft Consts.h"
#include "Consts.h"
#include "WarcraftFunction.h"

unsigned int ObjectToHandleId(ptr_t address)
{
    size_t pData = this_call(Warcraft::pGetHandleId, read<size_t>(Warcraft::pGameState));

    if (pData > 0)
    {
        return this_call(Warcraft::pObjectToHandleId, pData, (size_t)address, 0);
    }

    return 0;
}


std::string GetIdFromPtr(ptr_t ptr)
{
    char buffer[5];
    buffer[4] = 0;
    write<int>((ptr_t)buffer, read<int>(ptr));
    return std::string(buffer);
}

unsigned int GetGameType() {
    unsigned int result = 0;

    ptr_t gamestate = read<ptr_t>(pGame + 0xAB65F4);

    if (gamestate != nullptr) {
        result |= GAMEFLAG_OK;

        bool loading = read<bool>(gamestate + 0x10);
        unsigned int ingame = read<unsigned int>(gamestate + 0x8);

        if (loading) {
            result |= GAMEFLAG_LOADING;
        }

        if (ingame) {
            result |= GAMEFLAG_INGAME;
        }
    }

    return result;
}