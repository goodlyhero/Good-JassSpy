#include <Windows.h>
#include <format>
#include <fstream>
#include <vector>
#include <map>
#include <tuple>

#include "Consts.h"
#include "Warcraft Consts.h"
#include "Calls.h"
#include "HookHelper.h"
#include "Memory.h"
#include "jvm_levels.h"
#include "WarcraftFunction.h"

ptr_t punit;

using coord = std::tuple<float, float, float>;

std::map<size_t, coord> coords;


void PrintUnitPos(ptr_t punit)
{
	static std::ofstream out("UnitPos_Log.txt");
	ptr_t pos_dat = punit + 0x164;
	//std::cout << pos_dat << "    " << std::endl;
	float buffer[3];
	ptr_t ptr = (ptr_t)this_call(Warcraft::GetCoordFromSmartPos,(size_t)pos_dat,(size_t) buffer);
	float x,y,z;
	x = read<float>((ptr_t)buffer);
	y = read<float>((ptr_t)buffer+4);
	z = read<float>((ptr_t)buffer+8);
	size_t handle = ObjectToHandleId(punit);
	auto result = coords.find(handle);
	bool write = false;
	float oldx;
	float oldy;
	float oldz;
	if (result == coords.end())
	{
		write = true;
	}
	else
	{
		coord dat = result->second;
		oldx = std::get<0>(dat);
		oldz = std::get<2>(dat);
		oldy = std::get<1>(dat);
		if (oldx != x || oldy != y || oldz != z)
		{
			write = true;
		}
	}
	if (write)
	{
		out << std::format("handle: {} ({}) x: {:f} y: {:f} z: {:f}",handle,handle==0?"NULL": GetIdFromPtr(punit+0x30), x, y, z) << std::endl;
		coords[handle] = coord(x, y, z);
	}
}

void __declspec(naked) __cdecl PrintPosHook2()
{
	__asm push EBP;
	__asm push ECX;
	__asm push EDX;
	__asm push EAX;
	__asm push EBX;
	__asm mov EBP, ESP;
	{
		__asm
		{
			mov punit, ECX;
		}
		PrintUnitPos(punit);
	}
	__asm pop EBX;
	__asm pop EAX;
	__asm pop EDX;
	__asm pop ECX;
	__asm pop EBP;
	__asm
	{
		add ESP,4
		mov EAX, ECX;
		add EAX, 0x164;
		ret;
	}
}

void InitUnitPosHook()
{
	PlantDetourCall(Warcraft::GetUnitPosHook, (ptr_t)&PrintPosHook2);
}