#include "iter.hpp"

int main( void ) 
{
    int _int[] = {
        0,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
    };

    std::cout << "{" << std::endl;
    iter(_int,10,&multiplyByPi);
    print(_int, 10);
    std::cout << "}" << std::endl;

    const int constInt[] = {
        0,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
    };

    std::cout << "{" << std::endl;
    iter(constInt,10,&multiplyByPi);
    std::cout << std::endl;
    std::cout << "}" << std::endl;

    try {
        char * p = NULL;
        iter(p, 100,&multiplyByPi);
    } catch ( std::exception &e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }

    return 0;
}