#include "Cat.hpp"

Cat::Cat(void): Animal() { 
	std::cout << "Cat Default constructor called" << std::endl;
    type_ = "Cat";
	brain = new Brain();
}

Cat::~Cat( void ) {
	std::cout << "Cat Default destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound( void ) const {}


