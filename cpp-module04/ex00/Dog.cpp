#include "Dog.hpp"

Dog::Dog( void ) : Animal() { 
	std::cout << "Dog Default constructor called" << std::endl;
    type_ = "Dog";
}

Dog::~Dog( void ) { std::cout << "Dog Default destructor called" << std::endl; };

void Dog::makeSound( void ) const { std::cout << "woof" << std::endl; }