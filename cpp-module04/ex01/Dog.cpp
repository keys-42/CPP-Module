#include "Dog.hpp"

Dog::Dog(void)
	: Animal("Dog") {
	std::cout << "Dog Default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& d)
	: Animal(d) {
	*this = d;
}

Dog::~Dog(void) {
	delete this->brain;
	std::cout << "Dog Default destructor called" << std::endl;
};

Dog& Dog::operator=(const Dog& r) {
	if (this != &r) {
		this->type_ = r.getType();
		this->brain = new Brain(*r.brain);
	}
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "The dog is barking. woof woof!!!" << std::endl;
}
