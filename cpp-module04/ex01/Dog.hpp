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
        void setBrain(std::string ideas[100]);
        Brain *getBrain() const;
        Dog & operator = ( const Dog & r);

	private:
		Brain* brain;
};

#endif
