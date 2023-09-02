#include "Animal.hpp"

Animal::Animal() : type_(""){ std::cout << "Animal Default constructor called" << std::endl; }

Animal::~Animal(){ std::cout << "Animal Default destructor called" << std::endl; }

const std::string& Animal::getType( void ) const { return type_ ;};

void Animal::makeSound( void ) const { std::cout << "Animal" <<std::endl; }


void Animal::setType(const std::string& new_type)
{
    type_ = new_type;
}

Animal & Animal::operator = ( const Animal & r)
{
    this->setType(r.getType());
    return *this;
}

Brain *Animal::getBrain() const { return NULL; }