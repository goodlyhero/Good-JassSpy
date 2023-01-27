#include <map>

#include "jvm_levels.h"

namespace JVM_levels
{
	std::map<ptr_t, int> levels;
	int inclevel(ptr_t jvm)
	{
		int lvl = 0;
		auto node = levels.find(jvm);
		if (node != levels.end())
		{
			lvl = node->second + 1;
			node->second = lvl;
		}
		else
		{
			levels.insert({ jvm,1 });
		}
		return  std::max(lvl,0);
	}

	int getlevel(ptr_t jvm)
	{
		auto node = levels.find(jvm);
		int lvl = 0;
		if (node != levels.end())
		{
			lvl = node->second;
		}
		return std::max(lvl, 0);
	}

	int declevel(ptr_t jvm)
	{
		int lvl = 0;
		auto node = levels.find(jvm);
		if (node != levels.end())
		{
			lvl = node->second - 1;
			node->second = lvl;
		}
		else
		{
			levels.insert({ jvm,0 });
		}
		return  std::max(lvl, 0);
	}
}