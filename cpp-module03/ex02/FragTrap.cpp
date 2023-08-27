#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap defualt constructor called: " << name <<std::endl;
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
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
