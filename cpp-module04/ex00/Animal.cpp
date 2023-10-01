#include "Animal.hpp"

Animal::Animal() : type_("") {
  std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string name) : type_(name) {
  std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &a) { *this = a; }

Animal::~Animal() {
  std::cout << "Animal Default destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &r) {
  this->type_ = r.getType();
  return *this;
}

const std::string &Animal::getType(void) const { return type_; };

void Animal::makeSound(void) const {
  std::cout << "Animals cannot bark or meow." << std::endl;
}