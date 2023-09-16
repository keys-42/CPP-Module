#include "Serialize.hpp"

int main()
{
    Data a;
    uintptr_t u;
    Data *l;

    a.id_ = 1;
    a.name_ = "Jun";
    a.timestamp_ = std::time(0);
    std::cout << "a: [" << &a << "]" << std::endl;
    std::cout << "{" << std::endl;
    std::cout << "    " << a.id_ << std::endl;
    std::cout << "    " << a.name_ << std::endl;
    std::cout << "    " << a.timestamp_ << std::endl;
    std::cout << "}" << std::endl << std::endl;
    u = Serialize::serialize(&a);
    std::cout << "u: [" << u << "]" << std::endl;
    l = Serialize::deserialize(u);
    std::cout << "l: [" << l << "]" << std::endl << std::endl;
    std::cout << "{" << std::endl;
    std::cout << "    " << l->id_ << std::endl;
    std::cout << "    " << l->name_ << std::endl;
    std::cout << "    " << l->timestamp_ << std::endl;
    std::cout << "}" << std::endl;

    return (0);
}