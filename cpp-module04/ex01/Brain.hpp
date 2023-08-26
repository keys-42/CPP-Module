#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    public:
        Brain();
        ~Brain();
        
    private:
        std::string idea[100];
};

#endif