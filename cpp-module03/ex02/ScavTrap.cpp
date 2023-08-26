# include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "ScavTrap defualt constructor called: " << name <<std::endl;
}

ScavTrap::~ScavTrap(){ std::cout << "ScavTrap defualt destructor called" <<std::endl; }

void ScavTrap::attack(const std::string& target)
{
	if(!checkPoints())
		return;
	consumeEnergyPoints();
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" <<std::endl;
}


void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}