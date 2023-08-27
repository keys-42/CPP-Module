#include "Animal.hpp"

Animal::Animal() : type_(""){ std::cout << "Animal Default constructor called" << std::endl; }

Animal::~Animal(){ std::cout << "Animal Default destructor called" << std::endl; }

std::string Animal::getType( void ) const { return type_ ;};

void Animal::makeSound( void ) const { std::cout << "Animal" <<std::endl; }