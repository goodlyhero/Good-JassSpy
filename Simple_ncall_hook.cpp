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


void __fastcall CallNativeFunc_Hook_simple(ptr_t JVM, std::uint32_t u1, char* Func_name)
{
	static bool nonstop = true;
	if (nonstop)
	{
		int result = MessageBox(NULL, Func_name, "Calling func", MB_CANCELTRYCONTINUE);
		if (result == IDOK)
		{
			nonstop = false;
		}
	}

	this_call(Warcraft::CallNative, (size_t)JVM, (size_t)Func_name);
}

const char* GetStringFromRCString(ptr_t pRCString)
{
	ptr_t pCStringRep = read<ptr_t>(pRCString + 0x8);
	const char* result = read<char*>(pCStringRep + 0x1c);
	if (result == nullptr)
	{
		result = "null";
	}
	return result;
}


const char* GetStringFromJVM(ptr_t jvm, size_t id)
{
	ptr_t dataa = read<ptr_t>(jvm + 0x2874);
	ptr_t datab = read<ptr_t>(dataa + 8);
	ptr_t pstrrep = read<ptr_t>(datab + id * 0x10 + 0x8);
	const char* pstr = read<char*>(pstrrep + 0x1c);
	if (pstr == nullptr)
	{
		pstr = "null";
	}
	return pstr;
}
size_t __fastcall CallNativeFunc_Hook(ptr_t JVM, std::uint32_t u1, char* Func_name)
{
	int buffer[16];
	float fbuffer[16];
	ptr_t native_data = (ptr_t)this_call(Warcraft::GetNativeFromName, (size_t)Func_name);
	int argcnt = 0;
	char* signature = *(char**)(native_data + 0x24) + 1;
	int stack_argcnt = *(int*)(native_data + 0x20);
	int stack_arg = stack_argcnt - 1;
	ptr_t stack = (ptr_t)(((int)*(size_t*)(JVM + 0x2868) < 1) - 1 & *(size_t*)(JVM + 0x2868));//whut?
	int stack_top = *(int*)(stack + 0x8c);
	out() <<"ncall: "<<Func_name << "(" << std::endl;
	while (stack_arg > -1)
	{
		ptr_t arg_data = read<ptr_t>((stack + 8 + 4 * (stack_top - stack_arg)));
		char symbol = *signature;
		argcnt++;
		signature++;
		stack_arg--;
		int datatype = *(int*)(arg_data + 0x18);
		if (symbol == 'C' || (datatype != 3))
		{
			size_t data = read<size_t>(arg_data + 0x20);
			switch (symbol)
			{
			case 'C':
			{
				/*if (datatype == 3)
				{
					buffer[argcnt - 1] = 0;
				}*/
				//else
				//{
					buffer[argcnt - 1] = this_call(Warcraft::JVM_GetCode, (size_t)JVM, data);
				//}
				out() << std::format("Code: {:X},\n", buffer[argcnt - 1]);
				break;

			}
			case 'R':
			{
				auto f = read<float>((ptr_t)&data);
				fbuffer[argcnt] = f;
				buffer[argcnt - 1] = (size_t)(fbuffer + argcnt);
				out() << std::format("float: {:f},\n", f);
				break;
			}
			case 'S':
			{
				ptr_t s = (ptr_t)this_call(Warcraft::JVM_GetStringArg, (size_t)JVM, data);
				buffer[argcnt - 1] = (size_t)s;
				const char* pStr = GetStringFromRCString(s);
				out() << "string: " << pStr << ",\n";
				break;
			}
			case 'H':
			{
				while (symbol != ';') {
					signature++;
					symbol = *signature;
				}
				signature++;
				buffer[argcnt - 1] = data;
				out() << "Handle: " << (int)data << std::endl;
				break;
			}
			case 'I':
			{
				buffer[argcnt - 1] = data;
				out() << "Int: " << (int)data << std::endl;
				break;
			}
			case 'B':
			{
				buffer[argcnt - 1] = data;
				out() << "Bool: " << std::format("{:s}", data == 0 ? "false" : "true") << std::endl;
				break;
			}
			default:
			{
				buffer[argcnt - 1] = data;
				out() << (int)data << std::endl;
				break;
			}
			}
		}
		else
		{
			buffer[argcnt - 1] = 0;
			out() << "0,\n";
		}
	}
	ptr_t pfunc = (ptr_t)(*(int*)(native_data + 0x1c));

	size_t result = cdecl_call_variadic(pfunc, argcnt, buffer);
	signature += 1;
	out() << ")";
	switch ((char)*signature)
	{
	case 'I':
	case 'H':
	{
		out() << "->" << (int)result;
		break;
	}
	case 'R':
	{
		out() << std::format("->float: {:f}",(float)result);
		break;
	}
	case 'S':
	{
		out() << std::format("->string: {:s}", GetStringFromJVM(JVM,result));
		break;
	}
	case 'B':
	{
		out() <<std::format("->bool: {:s}", result == 0 ? "false" : "true");
		break;
	}
	}
	out() << std::endl;
	stack_top = *(int*)(stack + 0x8c);
	*(int*)(stack + 0x8c) = stack_top - stack_argcnt;
	return result;
}

void InitSimpleHook()
{
	PlantDetourCall(Warcraft::JVM_CallNativeFunctionCall, (ptr_t)&CallNativeFunc_Hook);
}