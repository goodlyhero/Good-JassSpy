#pragma once
#include "type_allias.h"
#include <string>

unsigned int ObjectToHandleId(ptr_t address);
std::string GetIdFromPtr(ptr_t ptr);
