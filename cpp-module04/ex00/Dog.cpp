#include "Dog.hpp"

Dog::Dog( void ) : Animal() { 
	std::cout << "Dog Default constructor called" << std::endl;
    type_ = "dog";
}
Dog::~Dog( void ) {};

void Dog::makeSound( void ) const 
{
	std::cout << "Dog Default destructor called" << std::endl;
    std::cout << "wnwnwnwnwnnwnw!" << std::endl;
}