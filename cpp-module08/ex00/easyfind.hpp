#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <exception>


class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() { return "Number was not found in the container."; }
};

template <typename T>
void easyfind(T container, int n)
{
    typename T::iterator itr;
    bool found = false;
    
    for ( itr = container.begin();itr != container.end(); ++itr) {
        if(*itr == n) {
            found = true;
            break;
        }
    }
    if(found)
        std::cout << "Number was found" << std::endl;
    else
        throw NotFoundException();
        
}

#endif