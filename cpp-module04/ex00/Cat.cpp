#include "Cat.hpp"

Cat::Cat(void): Animal() { 
	std::cout << "Cat Default constructor called" << std::endl;
    type_ = "cat";
}

Cat::~Cat( void ){}

void Cat::makeSound( void ) const
{
	std::cout << "Cat Default destructor called" << std::endl;
    std::cout << "" << std::endl;
}