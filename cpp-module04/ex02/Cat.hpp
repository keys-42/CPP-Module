#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    public:
        Cat();
        virtual ~Cat();
        void makeSound();

		private:
			Brain* brain;

};

#endif
