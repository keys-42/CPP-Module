#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type_;
    
    public:
        Animal();
        virtual ~Animal();
        const std::string& getType( void ) const ;
        void setType(const std::string& new_type);
        virtual void makeSound(void) const ;
        virtual Brain* getBrain() const;
        Animal & operator = ( const Animal & r);
};

#endif
