#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert [string]" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);

    // ScalarConverter *p = new ScalarConverter();
    // delete p;
    
    return (0);
}