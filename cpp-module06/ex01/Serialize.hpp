#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include "Data.hpp"

// #if defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__)
// typedef unsigned long long uintptr_t;
// #else
// typedef unsigned long uintptr_t;
// #endif

class Serialize {
private:
	Serialize(){};

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
