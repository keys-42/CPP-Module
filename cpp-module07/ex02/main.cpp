#include "Array.hpp"

#define N 5;

int main()
{
    unsigned int n = (unsigned int)N;
    Array<int> a(n);
    Array<int> b(n);
    Array<int> c(a);

    b = a;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    
    
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i ;
    for (unsigned int i = 0; i < a.size(); i++)
        b[i] = i * M_PI;
    for (unsigned int i = 0; i < a.size(); i++)
        c[i] = a[i] * b[i];
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    try {
        std::cout << a[0] << std::endl;
    } catch (Array<int>::OutOfBoundsException &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << a[4] << std::endl;
    } catch (Array<int>::OutOfBoundsException &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << a[5] << std::endl;
    } catch (Array<int>::OutOfBoundsException &e) {
        std::cout << e.what() <<std::endl;
    }
    try {
        std::cout << a[100] << std::endl;
    } catch (Array<int>::OutOfBoundsException &e) {
        std::cout << e.what() <<std::endl;
    }
    return 0;
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q array");
// }