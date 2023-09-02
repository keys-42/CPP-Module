#include "Cat.hpp"

Cat::Cat(void): Animal() { 
	std::cout << "Cat Default constructor called" << std::endl;
    type_ = "Cat";
	brain = new Brain();
}

Cat::~Cat( void ) {
	delete brain;
	std::cout << "Cat Default destructor called" << std::endl;
}

void Cat::makeSound( void ) const {}

Brain *Cat::getBrain() const
{
	return brain;
}

Cat & Cat::operator = ( const Cat & r)
{
	this->brain = r.brain;
	return *this;
}
