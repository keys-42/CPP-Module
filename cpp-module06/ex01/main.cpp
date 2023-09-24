#include "Serialize.hpp"

int main()
{
    Data before;
    uintptr_t uintptr;
    Data *after;

    before.id_ = 1;
    before.name_ = "Jun";
    before.timestamp_ = std::time(0);
    std::cout << "before: [" << &before << "]" << std::endl;
    std::cout << "{" << std::endl;
    std::cout << "    id    :" << before.id_ << std::endl;
    std::cout << "    name  :" << before.name_ << std::endl;
    std::cout << "    time  :" << before.timestamp_ << std::endl;
    std::cout << "}" << std::endl << std::endl;
    uintptr = Serialize::serialize(&before);
    std::cout << "uintptr: [" << uintptr << "]" << std::endl;
    after = Serialize::deserialize(uintptr);
    std::cout << "after: [" << after << "]" << std::endl << std::endl;
    std::cout << "{" << std::endl;
    std::cout << "    id    :" << after->id_ << std::endl;
    std::cout << "    name  :" << after->name_ << std::endl;
    std::cout << "    time  :" << after->timestamp_ << std::endl;
    std::cout << "}" << std::endl;

    // Serialize *p = new Serialize();
    // delete p;

    return (0);
}