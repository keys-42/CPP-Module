#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    public:
        Dog();
        virtual ~Dog();
        void makeSound( void ) const;

	private:
		Brain* brain;
};

#endif
