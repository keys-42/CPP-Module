#include "iter.hpp"

int main( void ) 
{
    std::string arr[] = {
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "{" << std::endl;
    iter(arr,size,&func);
    std::cout << "}" << std::endl;

    const std::string constArr[] = {
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
    };

    std::cout << "{" << std::endl;
    iter(constArr,size,&func);
    std::cout << "}" << std::endl;

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

    std::cout << "}" << std::endl;
    iter(_int,10,&multiplyByPi);
    std::cout << "{" << std::endl;

    int constInt[] = {
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

    std::cout << "}" << std::endl;
    iter(constInt,10,&multiplyByPi);
    std::cout << "{" << std::endl;

    return 0;
}