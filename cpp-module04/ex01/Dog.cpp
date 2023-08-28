#include "Dog.hpp"

Dog::Dog( void ) : Animal() { 
	std::cout << "Dog Default constructor called" << std::endl;
    type_ = "Dog";
		brain = new Brain();
}

Dog::~Dog( void ) { 
	std::cout << "Dog Default destructor called" << std::endl; 
	delete brain;
};

void Dog::makeSound( void ) const { std::cout << "woof" << std::endl; }
