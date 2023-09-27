#include "iter.hpp"

template <typename T>
void multiplyByPi(T &value) {
    std::cout << std::setw(6) << static_cast<int>(M_PI) * value << std::endl;
}

template <typename T>
void assignment(T &value) {
    value = 0;
}

template <typename T>
void print(T &value) {
    std::cout << value;
}

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

    try {
        std::cout << "{" << std::endl;
        iter(_int,10,multiplyByPi<int>);
        std::cout << std::endl;
        std::cout << "}" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

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
    try {
        std::cout << "{" << std::endl;
        iter(constInt,10,&multiplyByPi<const int>);
        std::cout << std::endl;
        std::cout << "}" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        char * p = NULL; 
        iter(p, 100,&multiplyByPi);
    } catch ( std::exception &e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }

    try {
        iter(_int, 10, &assignment<int>);
        iter(_int, 10, &print<int>);
    } catch ( std::exception &e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        // iter(constInt, 10, &assignment<const int>);
        iter(constInt, 10, &print<const int>);
    } catch ( std::exception &e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }

    return 0;
}
