#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
    public:
        Dog();
        virtual ~Dog();
        void makeSound();
    
    private:
        Brain* brain_;
};

#endif