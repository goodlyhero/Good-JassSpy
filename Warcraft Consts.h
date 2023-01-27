#pragma once

#include <iostream>
#include "type_allias.h"
namespace Warcraft
{
	extern ptr_t CallNative;
	extern ptr_t CallNativeFromName;
	extern ptr_t GetNativeFromName;
	extern ptr_t JVM_GetCode;
	extern ptr_t JVM_GetStringArg;
	extern ptr_t JVM_CallNativeFunctionCall;
	extern ptr_t JVM_jCallNativeFunctionCall;
	extern ptr_t JVM_CallJassFunction;
	extern ptr_t GetCoordFromSmartPos;
	extern ptr_t pObjectToHandleId;
	extern ptr_t pGameState;
	extern ptr_t pGetHandleId;


	extern ptr_t JVM_RetHook;
	extern ptr_t JVM_UnkRetCall;
	extern ptr_t IssueImmediateOrderTimed;
	extern ptr_t IssueImmediateOrderBack;
	extern ptr_t IssuePointOrder;
	extern ptr_t IssuePointOrderBack;
	extern ptr_t GetUnitPosHook;
	extern ptr_t SetAgentPresenceHook;


}

void InitWarcraftConsts();