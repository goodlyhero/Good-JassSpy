#pragma once

#include <fstream>

inline std::ofstream& out()
{
	static std::ofstream out("jass_log.txt");
	return out;
}