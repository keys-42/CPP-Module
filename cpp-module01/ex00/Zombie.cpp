#include "Zombie.hpp"

Zombie::Zombie()
	: name_("") {}

Zombie::Zombie(const std::string& name)
	: name_(name) {}

void Zombie::announce() const {
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name_ << ": ~Zombie" << std::endl;
}
