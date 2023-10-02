#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(const std::string& name)
	: name_(name) {}

void Zombie::setName(const std::string& name) const {
	name_ = name;
};

void Zombie::announce() const {
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name_ << ": ~Zombie" << std::endl;
}
