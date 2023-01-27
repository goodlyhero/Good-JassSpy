#include <Windows.h>
#include <format>
#include <fstream>

#include "Consts.h"
#include "Warcraft Consts.h"
#include "Calls.h"
#include "HookHelper.h"
#include "Memory.h"
#include "out.h"
#include "jvm_levels.h"


void __fastcall jvm_ret_hook(size_t, ptr_t pthreadinfo)
{
	ptr_t jvm = pthreadinfo - 0x2864;
	out() << "}" << std::endl;
	cdecl_call(Warcraft::JVM_UnkRetCall);
}

void Init_jvm_ret_hook()
{
	PlantDetourCall(Warcraft::JVM_RetHook, (ptr_t)jvm_ret_hook);
}