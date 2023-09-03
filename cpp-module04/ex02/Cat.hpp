#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat: public AAnimal
{
    private:
        Brain *brain;

    public:
        Cat();
        Cat(const Cat & c);
        virtual ~Cat();
        Cat & operator= ( const Cat & r);
        void makeSound( void ) const;
};

#endif