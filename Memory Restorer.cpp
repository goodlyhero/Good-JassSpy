
#include <map>

#include "Memory.h"
#include "Memory Restorer.h"


class MemoryRestorer
{
private:
	std::map<ptr_t, std::byte> DataMap;
public:
	MemoryRestorer();
	~MemoryRestorer();
	void AddOffsetToRestoreFromExistingData(ptr_t pData, size_t len);
	void RestorePtr(ptr_t pData);
	void RestoreInterval(ptr_t pData, size_t len);
};


MemoryRestorer::MemoryRestorer() :DataMap() {};
MemoryRestorer::~MemoryRestorer()
{
	for (auto& ptr : DataMap)
	{
		writeSafe<std::byte>((ptr.first), ptr.second);
	}
	DataMap.clear();
}

void MemoryRestorer::AddOffsetToRestoreFromExistingData(ptr_t pData, size_t len)
{
	for (ptr_t ptr = pData; ptr < pData + len; ptr++)
	{
		DataMap[ptr] = read<std::byte>(ptr);
	}
}
void MemoryRestorer::RestorePtr(ptr_t pData)
{
	auto  idata = DataMap.find(pData);
	if (idata != DataMap.end())
	{
		auto data = *idata;
		writeSafe<std::byte>(pData, data.second);
	}
}
void MemoryRestorer::RestoreInterval(ptr_t pData, size_t len)
{
	for (ptr_t ptr = pData; ptr < pData + len; ptr++)
	{
		RestorePtr(ptr);
	}
}

MemoryRestorer Restorer;

void AddOffsetToRestoreFromExistingData(ptr_t pData, size_t len)
{
	Restorer.AddOffsetToRestoreFromExistingData(pData, len);
}
void RestorePtr(ptr_t pData)
{
	Restorer.RestorePtr(pData);
}

void RestoreInterval(ptr_t pData, size_t len)
{
	Restorer.RestoreInterval(pData, len);
}