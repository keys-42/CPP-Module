#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Animal
{
    protected:
        std::string type_;
    
    public:
        Animal();
        virtual ~Animal();
        const std::string& getType( void ) const ;
        virtual void makeSound(void) const ;
};

#endif
