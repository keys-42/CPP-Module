#include "Dog.hpp"

Dog::Dog( void ) : Animal() { 
	std::cout << "Dog Default constructor called" << std::endl;
    type_ = "dog";
    brain_ = new Brain();
}
Dog::~Dog( void ) {
	std::cout << "Dog Default destructor called" << std::endl;
    brain_ = new Brain();
};

void Dog::makeSound( void ) const 
{
	std::cout << "Dog Default destructor called" << std::endl;
    std::cout << "wnwnwnwnwnnwnw!" << std::endl;
}