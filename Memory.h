#pragma once

#include <utility>
#include <Windows.h>

#include "type_allias.h"

template <typename Type>
Type read(ptr_t pData)
{
	if((size_t)pData < 500)
	{
		return Type(0);
	}
	return *(Type*)pData;
}

template <typename Type>
bool write(ptr_t target, Type data)
{
	if((size_t)target < 500)
	{
		return false;
	}
	*(Type*)target = data;
	return true;
}

const auto readInt = read<std::int32_t>;
const auto writeInt = write<std::int32_t>;
const auto readFloat = read<float_t>;
const auto writeFloat = write<float_t>;

template <typename Type>
Type readSafe(ptr_t pData)
{
	DWORD oldprotect = NULL;
	if (!VirtualProtect(pData, sizeof(Type), PAGE_EXECUTE_READWRITE, &oldprotect))
	{
		return Type(0);
	}
	Type result = read<Type>(pData);
	VirtualProtect(pData, sizeof(Type), oldprotect, NULL);
	return result;
}

template <typename Type>
bool writeSafe(ptr_t source, Type data)
{
	DWORD oldprotect = NULL;
	if (!VirtualProtect(source, sizeof(Type), PAGE_EXECUTE_READWRITE, &oldprotect))
	{
		return false;
	}
	auto result = write<Type>(source,data);
	VirtualProtect(source, sizeof(Type), oldprotect, NULL);
	return result;
}

const auto readIntSafe = readSafe<std::int32_t>;
const auto writeIntSafe = writeSafe<std::int32_t>;
const auto readFloatSafe = readSafe<float_t>;
const auto writeFloatSafe = writeSafe<float_t>;