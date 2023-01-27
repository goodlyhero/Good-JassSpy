#include "Calls.h"
#include "Memory.h"
#include "type_allias.h"
#include "Warcraft Consts.h"

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