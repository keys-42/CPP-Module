#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    public:
        Cat();
        virtual ~Cat();
        void makeSound( void ) const;

    private:
        Brain* brain_;
};

#endif