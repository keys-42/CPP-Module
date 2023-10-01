#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
  std::cout << "WrongCat Default constructor called" << std::endl;
  type_ = "WrongCat";
}

WrongCat::~WrongCat(void) {
  std::cout << "WrongCat Default destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
  std::cout << "the WrongCat is meowing. meow meow!" << std::endl;
}