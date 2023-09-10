#include "iter.hpp"

void printLength(std::string &s)
{
    std::cout << std::setw(10) << s.length() << std::endl;
}

void multiplyByPi(int &value) {
    double result = value * M_PI;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << std::setw(10) << result << std::endl;
}

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
    std::cout << "{" << std::endl;
    iter(arr,size,&printLength);
    std::cout << "}" << std::endl;

    int i[] = {
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
    std::cout << "{" << std::endl;
    iter(i,10,&multiplyByPi);


    return 0;
}