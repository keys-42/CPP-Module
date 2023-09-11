#include "easyfind.hpp"
# define N 10

int main()
{
    std::vector<int> v;
    std::list<int> l;
    for (int i=0; i < N; i++) {
        v.push_back(i);
        l.push_back(i);
        if((i % 2) == 1) {
            l.push_back(i - 1);
        }
    }

    std::cout << "=============vector=============" << std::endl;
    try {
        for ( int i = 0; i >= 0; i++ ) {
            std::cout << i << ": " << std::setw(20);
            easyfind<std::vector<int> >(v, i);
        }
    } catch (NotFoundException &e) {
        std::cout << std::setw(14) << "exception: " << e.what() << std::endl;
    }

    std::cout << "=============list=============" << std::endl;
    try {
        for ( int i = 0; i >= 0; i++ ) {
            std::cout << i << ": " << std::setw(20);
            easyfind<std::list<int> >(l, i);
        }
    } catch (NotFoundException &e) {
        std::cout << std::setw(14) << "exception: " << e.what() << std::endl;
    }
}