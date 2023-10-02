#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include "Data.hpp"

typedef unsigned long long uintptr_t;

class Serialize {
private:
	Serialize(){};

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
