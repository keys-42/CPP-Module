#include "Cat.hpp"

Cat::Cat(void): Animal() { 
	std::cout << "Cat Default constructor called" << std::endl;
    type_ = "Cat";
}

Cat::~Cat( void ) { std::cout << "Cat Default destructor called" << std::endl; }

void Cat::makeSound( void ) const {}