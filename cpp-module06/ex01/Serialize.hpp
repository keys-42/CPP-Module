#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

# include <cstdint>
#include "Data.hpp"

class Serialize
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif