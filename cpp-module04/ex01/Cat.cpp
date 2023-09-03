#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {  
    std::cout << "Cat Default constructor called" << std::endl; 
    this->brain = new Brain();
}

Cat::Cat(const Cat & c) : Animal(c) { *this = c; }

Cat::~Cat( void ) { 
    delete this->brain;
    std::cout << "Cat Default destructor called" << std::endl; 
}

Cat & Cat::operator=( const Cat & r)
{
    this->type_ = r.getType();
    this->brain = new Brain();
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << std::setw(13) << "cat makeSound" << ":" << std::endl;
}