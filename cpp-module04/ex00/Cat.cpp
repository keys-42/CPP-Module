#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {  std::cout << "Cat Default constructor called" << std::endl; }

Cat::~Cat( void ) { std::cout << "Cat Default destructor called" << std::endl; }

void Cat::makeSound( void ) const {
    std::cout << std::setw(13) << "cat makeSound" << ":" << std::endl;
}