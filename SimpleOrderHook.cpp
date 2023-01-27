#include <Windows.h>
#include <format>
#include <fstream>

#include "Consts.h"
#include "Warcraft Consts.h"
#include "Calls.h"
#include "HookHelper.h"
#include "Memory.h"
#include "jvm_levels.h"



void __cdecl PrintOrderImmediate(ptr_t ret, ptr_t buffer, INT32 order, ptr_t pabil, INT32 bool1, INT32 bool2)
{
	static std::ofstream out("orderlog_instant.txt");
	out << std::format("Instant Timed Order: pGame+0x{:X} delay: {:f} order: {:X} abil: {:s} bool1: {:s} bool2: {:s}",
		(int)(ret-pGame),read<float>(buffer),order,pabil==nullptr?"NULL": (char*)this_call(read<ptr_t>(read<ptr_t>(pabil)+22*4),0), bool1 == 0 ? "false" : "true", bool2 == 0 ? "false" : "true") << std::endl;
}

ptr_t rret;
ptr_t pbuffer;
ptr_t pbuffer2;
INT32 order;
ptr_t pAbil;
int bool1;
int bool2;
int dat1;
int dat2;

void __declspec(naked) __cdecl PrintOrderImmediate2()
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
			mov EAX, [ESP+0x18];
			mov rret, EAX;
			mov EAX, [ESP + 0x1c];
			mov pbuffer, EAX;
			mov EAX, [ESP + 0x20];
			mov order, EAX;
			mov EAX, [ESP + 0x24];
			mov pAbil, EAX;
			mov EAX, [ESP + 0x28];
			mov bool1, EAX;
			mov EAX, [ESP + 0x2c];
			mov bool2, EAX;
		}
		PrintOrderImmediate(rret, pbuffer, order, pAbil, bool1, bool2);
	}
	__asm pop EBX;
	__asm pop EAX;
	__asm pop EDX;
	__asm pop ECX;
	__asm pop EBP;
	__asm
	{
		push 0xFFFFFFFF
		jmp Warcraft::IssueImmediateOrderBack;
	}
}

void PrintOrderPoint(ptr_t ret, INT32 order, INT32 dat1, INT32 dat2, ptr_t pbuffer1, ptr_t pbuffer2, INT32 bool1, INT32 bool2)
{
	static std::ofstream out("orderlog_point.txt");

	out << std::format("Point Order: pGame+0x{:X} order: {:X} dat1: {:X} dat2: {:X} x: {:f} y: {:f} bool1: {:X} bool2: {:X}",
		(int)(ret - pGame), order, dat1,dat2,read<float>(pbuffer1),read<float>(pbuffer2),bool1,bool2) << std::endl;
}

void __declspec(naked) __cdecl PrintOrderPoint2()
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
			mov EAX, [ESP + 0x18];
			mov rret, EAX;
			mov EAX, [ESP + 0x1c];
			mov order, EAX;
			mov EAX, [ESP + 0x20];
			mov dat1, EAX;
			mov EAX, [ESP + 0x24];
			mov dat2, EAX;
			mov EAX, [ESP + 0x28];
			mov pbuffer, EAX;
			mov EAX, [ESP + 0x2c];
			mov pbuffer2, EAX;
			mov EAX, [ESP + 0x30];
			mov bool1, EAX;
			mov EAX, [ESP + 0x34];
			mov bool2, EAX;
		}
		PrintOrderPoint(rret, order, dat1,dat2,pbuffer,pbuffer2,bool1,bool2);
	}
	__asm pop EBX;
	__asm pop EAX;
	__asm pop EDX;
	__asm pop ECX;
	__asm pop EBP;
	__asm
	{
		add ESP,4
		mov eax, [esp + 0x04]
		mov edx, [esp + 0x0C]
		jmp Warcraft::IssuePointOrderBack;
	}
}

void InitImmediateOrderHook()
{
	PlantDetourCall(Warcraft::IssueImmediateOrderTimed, (ptr_t)&PrintOrderImmediate2);
}

void InitPointOrderHook()
{
	PlantDetourCall(Warcraft::IssuePointOrder, (ptr_t)&PrintOrderPoint2);
}