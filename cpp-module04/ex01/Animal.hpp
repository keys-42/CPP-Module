#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <iomanip>
# include "Brain.hpp"

class Animal
{
    protected:
        std::string type_;
    
    public:
        Animal();
        Animal(std::string name);
        Animal(const Animal & a);
        virtual ~Animal();
        Animal & operator= ( const Animal & r);
        const std::string& getType( void ) const ;
        virtual void makeSound(void) const ;
};

#endif
