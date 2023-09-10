#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate(void) {
    
    srand(static_cast<unsigned>(time(0)));
    int choice = rand() % 3;

    if(choice == 0)
    {
        Base *base = new A();
        std::cout << "A was created." << std::endl;
        return base;
    }
    else if(choice == 1)
    {
        Base *base = new B();
        std::cout << "B was created." << std::endl;
        return base;
    }
    std::cout << "C was created." << std::endl;
    Base *base = new C();
    return base;
}

void identify(Base* p) {
    try {
        if(dynamic_cast<A *>(p))
            std::cout << "A" << std::endl;
        else if(dynamic_cast<B *>(p))
            std::cout << "B" << std::endl;
        else if(dynamic_cast<C *>(p))
            std::cout << "C" << std::endl;
    } catch(const std::bad_cast& e) {
        std::cout << e.what() << std::endl;
    }
}

void identify(Base& p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return ;
    } catch (std::bad_cast&){
        std::cout << "Not Type A" << std::endl;
    }

    try {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return ;
    } catch (std::bad_cast&){
        std::cout << "Not Type B" << std::endl;
    }

    try {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    } catch (std::bad_cast&){
        std::cout << "Not Type C" << std::endl;
    }
}

int main()
{
    Base *base;
    
    base = generate();
    identify(base);
    identify(*base);

    delete base;
    return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q realType");
// }
