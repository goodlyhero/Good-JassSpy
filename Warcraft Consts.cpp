#include <iostream>

#include "Consts.h"
#include "Warcraft Consts.h"

namespace Warcraft
{
	ptr_t CallNative;
	ptr_t CallNativeFromName;
	ptr_t GetNativeFromName;
	ptr_t JVM_GetCode;
	ptr_t JVM_GetStringArg;
	ptr_t JVM_CallNativeFunctionCall;
	ptr_t JVM_jCallNativeFunctionCall;
	ptr_t JVM_CallJassFunction;
	ptr_t JVM_RetHook;
	ptr_t JVM_UnkRetCall;
	ptr_t pObjectToHandleId;
	ptr_t pGameState;
	ptr_t pGetHandleId;


	ptr_t IssueImmediateOrderTimed;
	ptr_t IssueImmediateOrderBack;
	ptr_t IssuePointOrder;
	ptr_t IssuePointOrderBack;
	ptr_t GetCoordFromSmartPos;
	ptr_t GetUnitPosHook;
	ptr_t SetAgentPresenceHook;
}

void InitWarcraftConsts()
{
	using namespace Warcraft;
	CallNative = pGame +         0x45d070;
	CallNativeFromName = pGame + 0x44ea00;
	GetNativeFromName = pGame +	  0x44ea00;
	JVM_GetCode = pGame +        0x45ce50;
	JVM_GetStringArg = pGame +	  0x459640;
	JVM_CallNativeFunctionCall = pGame + 0x45efa9;
	JVM_jCallNativeFunctionCall = pGame + 0x45eff6;
	JVM_CallJassFunction = pGame + 0x45e8e0;
	GetCoordFromSmartPos = pGame + 0x4742f0;
	pObjectToHandleId = pGame + 0x430C80;
	pGameState = pGame + 0xAB65F4;
	pGetHandleId = pGame + 0x3A8060;



	JVM_RetHook = pGame + 0x45f7f0;
	JVM_UnkRetCall = pGame + 0x449ce0;
	IssueImmediateOrderTimed = pGame + 0x4778f0;
	IssueImmediateOrderBack = pGame + 0x4778f7;
	IssuePointOrder = pGame + 0x2860b0;
	IssuePointOrderBack = pGame + 0x2860B8;
	GetUnitPosHook = pGame + 0x28b0e0;
	SetAgentPresenceHook = pGame + 0x471f90;


}
