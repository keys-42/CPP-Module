#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
    private:
        Brain* brain;

    public:
        Dog();
        Dog(const Dog & d);
        virtual ~Dog();
        Dog & operator= ( const Dog & r);
        void makeSound( void ) const;
};

#endif