#pragma once
#include <iostream>

#include <format>

#include <Windows.h>
#include "type_allias.h"
inline size_t this_call(ptr_t pfuncaddr, size_t arg1)
{
	return ((size_t(__thiscall*) (size_t i1))pfuncaddr)(arg1);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2))pfuncaddr)(arg1, arg2);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2, size_t i3))pfuncaddr)(arg1, arg2, arg3);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2, size_t i3, size_t i4))pfuncaddr)(arg1, arg2, arg3, arg4);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5))pfuncaddr)(arg1, arg2, arg3, arg4, arg5);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
inline size_t this_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11, size_t arg12)
{
	return ((size_t(__thiscall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1)
{
	return ((size_t(__fastcall*) (size_t i1))pfuncaddr)(arg1);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2))pfuncaddr)(arg1, arg2);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2, size_t i3))pfuncaddr)(arg1, arg2, arg3);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2, size_t i3, size_t i4))pfuncaddr)(arg1, arg2, arg3, arg4);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5))pfuncaddr)(arg1, arg2, arg3, arg4, arg5);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
inline size_t fast_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11, size_t arg12)
{
	return ((size_t(__fastcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
inline size_t cdecl_call(ptr_t pfuncaddr)
{
	return ((size_t(__cdecl*) ())pfuncaddr)();
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1)
{
	return ((size_t(__cdecl*) (size_t i1))pfuncaddr)(arg1);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2))pfuncaddr)(arg1, arg2);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3))pfuncaddr)(arg1, arg2, arg3);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4))pfuncaddr)(arg1, arg2, arg3, arg4);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5))pfuncaddr)(arg1, arg2, arg3, arg4, arg5);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11, size_t arg12)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11, size_t arg12, size_t arg13)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11, size_t arg12, size_t arg13, size_t arg14)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t,size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13,arg14);
}
inline size_t cdecl_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11, size_t arg12, size_t arg13, size_t arg14, size_t arg15)
{
	return ((size_t(__cdecl*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t,size_t,size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13,arg14,arg15);
}
inline size_t std_call(ptr_t pfuncaddr)
{
	return ((size_t(__stdcall*) ())pfuncaddr)();
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1)
{
	return ((size_t(__stdcall*) (size_t i1))pfuncaddr)(arg1);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2))pfuncaddr)(arg1, arg2);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3))pfuncaddr)(arg1, arg2, arg3);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4))pfuncaddr)(arg1, arg2, arg3, arg4);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5))pfuncaddr)(arg1, arg2, arg3, arg4, arg5);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11, size_t arg12)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
}

inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11, size_t arg12, size_t arg13)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13);
}
inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11, size_t arg12, size_t arg13, size_t arg14)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
}

inline size_t std_call(ptr_t pfuncaddr, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5, size_t arg6, size_t arg7, size_t arg8, size_t arg9, size_t arg10, size_t arg11, size_t arg12, size_t arg13, size_t arg14, size_t arg15)
{
	return ((size_t(__stdcall*) (size_t i1, size_t i2, size_t i3, size_t i4, size_t i5, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t))pfuncaddr)(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
}

inline size_t std_call_variadic(ptr_t pfunc, int arg_cnt, int* buffer)
{
	int result;

	__asm{
		mov EDX, arg_cnt;
		mov EAX, buffer;
	check_dest:
		cmp EDX, 0;
		je call_dest;
		mov ECX, [buffer];
		push ECX;
		add EAX, 1;
		add EDX, -1;
		jmp check_dest;
	call_dest:
		mov ECX, pfunc;
		call ECX;
		mov result, EAX;
	}
	return result;
}

inline size_t cdecl_call_variadic_stupid(ptr_t pfunc, int arg_cnt, int* buffer)
{
	switch (arg_cnt)
	{
	case 0:
		return cdecl_call(pfunc);
	case 1:
		return cdecl_call(pfunc, buffer[0]);
	case 2:
		return cdecl_call(pfunc, buffer[0], buffer[1]);
	case 3:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2]);
	case 4:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3]);
	case 5:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
	case 6:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
	case 7:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
	case 8:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7]);
	case 9:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8]);
	case 10:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8], buffer[9]);
	case 11:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8], buffer[9], buffer[10]);
	case 12:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8], buffer[9], buffer[10], buffer[11]);
	case 13:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8], buffer[9], buffer[10], buffer[11], buffer[12]);
	case 14:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8], buffer[9], buffer[10], buffer[11], buffer[12], buffer[13]);
	case 15:
		return cdecl_call(pfunc, buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8], buffer[9], buffer[10], buffer[11], buffer[12], buffer[13], buffer[14]);
	default:
		MessageBox(NULL, std::format("FUCK, incorrect amount of arguments {:X}",(size_t)pfunc).c_str(), "FUCK", MB_OK);
	}
	return 0;
}

inline size_t cdecl_call_variadic(ptr_t pfunc, int arg_cnt, int* buffer)
{
	size_t stack = 0;
	int result = 0;
	__asm
	{
		mov stack, ESP;
		mov ECX, arg_cnt;
		mov EDX, buffer;
		mov EAX, arg_cnt;
		imul EAX, 4;
		sub EAX, 4;
		add EDX, EAX;
	check:
		cmp ECX, 0;
		je call_func;
		sub ECX, 1;
		mov EAX, [EDX];
		push EAX;
		sub EDX, 4;
		jmp check;
	call_func:
		mov EDX, pfunc;
		call EDX;
		mov result, EAX;
		mov ESP, stack;
	}
	return result;
}