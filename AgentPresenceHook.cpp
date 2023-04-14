#define _CRT_SECURE_NO_WARNINGS

#include "AgentPresenceHook.h"
#include <rcmp.hpp>
#include "Warcraft Consts.h"
#include "Consts.h"
#include "Memory.h"
#include <format>
#include <fstream>

#include "Calls.h"

#include "IniReader.h"

#include <unordered_set>
using namespace std;
#pragma comment(lib, "rcmp.lib")

template <typename... Args>
string dyna_print(string_view rt_fmt_str, Args&&... args) {
	return vformat(rt_fmt_str, make_format_args(args...));
}

std::unordered_set<unsigned long long> breaks;
bool use_breaks = false;

ptr_t GetEngineDataPointersWithId(DWORD id)
{
	return (ptr_t)this_call(pGame + 0x4c34d0, id);
}

ptr_t GetCNetData()
{
	auto d = GetEngineDataPointersWithId(0xd);
	if (d == nullptr) return nullptr;
	return read<ptr_t>(read<ptr_t>(d + 0x10) + 0x8);
}

DWORD GetTurn() {
	ptr_t CNet = GetCNetData();
	return read<DWORD>(CNet + 0x1c68);
}

DWORD GetTime() {
	ptr_t CNet = GetCNetData();
	return read<DWORD>(CNet + 0x1c70);
}

inline unsigned long long combine_numbers(unsigned int a, unsigned int b) {
	return (unsigned long long)a | (((unsigned long long)b) << 32);
}

volatile int counter = 0;
void __declspec(dllexport) __declspec(noinline) AgentPresence_BreakThisPlease(int presence, int born, size_t ptr)
{
	counter++;
}

void InitAgentPresenceHook() {
	auto settings = INIReader::INIReader("goodjasspy.ini");

	breaks.reserve(100);
	breaks.max_load_factor(0.25);
	use_breaks = settings.GetBoolean("breaks", "use_breaks", false);
	cout << use_breaks << endl;
	if (use_breaks) {
		int n_key = 0;
		while (true) {
			char buffer[256];
			sprintf_s(buffer, "born_%d", n_key);
			int born = settings.GetInteger("breaks",buffer,-1);
			sprintf_s(buffer, "presence_%d", n_key);
			int presence = settings.GetInteger("breaks",buffer,-1);
			if (born != -1 && presence != -1) {
				cout << "loaded tags: \n" << n_key << " " << presence << " " << born<<" "<<buffer<< endl;
				breaks.insert(combine_numbers(presence,born));
			}
			else {
				break;
			}
			n_key++;
		}
	}
	
	rcmp::hook_function<int(__thiscall*)(ptr_t, ptr_t) > (Warcraft::SetAgentPresenceHook, [](auto original, ptr_t agent, ptr_t data) {
		if (data != nullptr && readInt(data+0xc)==0x2b61676c && agent != nullptr && readInt(data+0x14)>0 && readInt(data+0x18)>0) {
			static ofstream Agentlog("agent_presence_log");
			ptr_t vftable = read<ptr_t>(agent);
			const char* type = "unk";
			if (vftable != 0) {
				type = (char*)this_call((ptr_t)readInt(vftable + 22 * 4),0);
			}
			DWORD turn = GetTurn();
			DWORD presence_tag = readInt(data + 0x14);
			DWORD born_tag = readInt(data + 0x18);
			/*if (48672 == turn && (((int32_t)vftable - (int32_t)pGame + 0x6f000000) == 0x6F93049C) && presence_tag == 0xF068 && born_tag == 0xB88B9) {
				DebugBreak();
			}*///dark minion desync check
			Agentlog << dyna_print("time: {:d}({:d}(ms)); VF: 0x{:X}({}); tags: (0x{:X},0x{:X})\n", turn, GetTime(),(int32_t)vftable - (int32_t)pGame+0x6f000000,type, presence_tag, born_tag);
			//cout<<"tags: "<<born_tag<<" "<<presence_tag<<" combo: "<< combine_numbers(presence_tag, born_tag)<< endl;
			if (use_breaks) {
				//cout << "breaks: true"<< endl;
				unsigned long long tags = combine_numbers(presence_tag, born_tag);
				if (breaks.find(tags)!=breaks.end()) {
					//cout << "breaking!"<< endl;
					AgentPresence_BreakThisPlease(presence_tag, born_tag,(size_t) data);
				}
			}
		}
		return  original(agent, data);
		});
}