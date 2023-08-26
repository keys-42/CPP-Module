#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap defualt constructor called: " << name <<std::endl;
}

FragTrap::~FragTrap(){ std::cout << "FragTrap defualt destructor called" <<std::endl; }

void FragTrap::attack(const std::string& target)
{
	if(!checkPoints())
		return;
	consumeEnergyPoints();
	std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" <<std::endl;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "Hey! Give me a positive high five!" << std::endl;
}
