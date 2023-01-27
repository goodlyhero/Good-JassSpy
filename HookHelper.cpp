#include "Memory.h"
#include "Memory Restorer.h"

void PlantDetourJump(ptr_t pSource, ptr_t pDestination)
{
	if (pSource == nullptr)
	{
		return;
	}
	if (!writeSafe<std::byte>(pSource, std::byte(0xE9)))
		return;
	DWORD Jump_len = (DWORD)pDestination - (DWORD)pSource - 5;
	if (!writeSafe<DWORD>(pSource+1, Jump_len))
	{
		//Restorer.RestoreInterval(pSource, 5);
	}
}

void PlantDetourCall(ptr_t pSource, ptr_t pDestination)
{
	if (pSource == nullptr)
	{
		return;
	}
	if (!writeSafe<std::byte>(pSource, std::byte(0xE8)))
		return;
	DWORD Jump_len = (DWORD)pDestination - (DWORD)pSource - 5;
	if (!writeSafe<DWORD>(pSource+1, Jump_len))
	{
		RestoreInterval(pSource, 5);
	}
}