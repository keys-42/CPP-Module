#include "RPN.hpp"

int main( int argc, char **argv )
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " {Reverse Polish Notation}" << std::endl;
        return 1;
    }
    (void)argv;
    
    return 0;
}
