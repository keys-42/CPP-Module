#include "Zombie.hpp"
Zombie::Zombie(){}

void Zombie::setName(std::string n)
{
	this->name_ = n;
}

void Zombie::announce()
{
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name_<< ": ~Zombie" << std::endl;
}
