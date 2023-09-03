#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_(""){ std::cout << "WrongAnimal Default constructor called" << std::endl; }

WrongAnimal::~WrongAnimal(){ std::cout << "WrongAnimal Default destructor called" << std::endl; }

std::string WrongAnimal::getType( void ) const { return type_ ;};

void WrongAnimal::makeSound( void ) const {
    std::cout << std::setw(22) << "WrongAnimal makeSound" << ":" << "WrongAnimal" <<std::endl; 
}