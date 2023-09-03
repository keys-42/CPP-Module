#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {  std::cout << "Cat Default constructor called" << std::endl; }

Cat::Cat(const Cat & c) : Animal(c) { *this = c; }

Cat::~Cat( void ) { std::cout << "Cat Default destructor called" << std::endl; }

Cat & Cat::operator=( const Cat & r)
{
    this->type_ = r.getType();
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << std::setw(13) << "cat makeSound" << ":" << std::endl;
}