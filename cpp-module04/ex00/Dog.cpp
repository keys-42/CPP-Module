#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") { std::cout << "Dog Default constructor called" << std::endl; }

Dog::Dog(const Dog & d) { *this = d; }

Dog::~Dog( void ) { std::cout << "Dog Default destructor called" << std::endl; };

Dog & Dog::operator= ( const Dog & r)
{
    this->type_ = r.getType();
    return *this;
}

void Dog::makeSound( void ) const {
    std::cout << std::setw(13) << "dog makeSound" << ":" << "woof" << std::endl; }