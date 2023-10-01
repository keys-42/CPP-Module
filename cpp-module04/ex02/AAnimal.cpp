#include "AAnimal.hpp"

AAnimal::AAnimal()
	: type_("") {
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string name)
	: type_(name) {
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& a) {
	*this = a;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal Default destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& r) {
	this->type_ = r.getType();
	return *this;
}

const std::string& AAnimal::getType(void) const {
	return type_;
};
