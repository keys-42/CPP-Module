#include "Serialize.hpp"

uintptr_t Serialize::serialize(Data* ptr) {
    uintptr_t ret;
    ret = reinterpret_cast<uintptr_t>(ptr);

    return ret;
}


Data* Serialize::deserialize(uintptr_t raw) {
    Data *ret;

    ret = reinterpret_cast<Data *>(raw);
    return ret;
}