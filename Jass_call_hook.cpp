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
size_t __fastcall hook_jcall(ptr_t jvm, int, char* func_name)
{
	out() << "call: "<< func_name << "{" << std::endl;
	size_t result =  this_call(Warcraft::JVM_CallJassFunction, (size_t)jvm, (size_t)func_name);
	return result;
}

void InitJcallHook()
{
	PlantDetourCall(Warcraft::JVM_jCallNativeFunctionCall, (ptr_t)&hook_jcall);
}