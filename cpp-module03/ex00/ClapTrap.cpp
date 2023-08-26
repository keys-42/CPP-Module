#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ){
	std::cout << "defualt constructor called: " << name <<std::endl;
	name_ = name ;
	hit_points_ = 10;
	energy_points_ = 10;
	attack_damage_ = 0;
}

ClapTrap::~ClapTrap(){ std::cout << "defualt destructor called" <<std::endl; }


void ClapTrap::attack(const std::string& target)
{
	if(!checkPoints())
		return;
	consumeEnergyPoints();
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" <<std::endl;
}



void ClapTrap::takeDamage(unsigned int amount){ 
	hit_points_-= amount;
	std::cout << "ClapTrap " << this->getName() << " takeDamage " << std::endl;
	
}
void ClapTrap::beRepaired(unsigned int amount){ 
	if(!checkPoints())
		return;
	consumeEnergyPoints();
	hit_points_ += amount;
	std::cout << "ClapTrap " << this->getName() << " beRepaired " << std::endl;
}

std::string ClapTrap::getName() const { return name_; }
			
long long ClapTrap::getAttackDamage() const { return attack_damage_; }

bool ClapTrap::checkPoints( void ) const { return hit_points_ && energy_points_; }

void ClapTrap::consumeEnergyPoints( void ) { energy_points_--; }

void ClapTrap::getInfo() const { 
	std::cout << "name: " << name_ << std::endl;
	std::cout << "hit_points: " << hit_points_ << std::endl;
	std::cout << "energy_ponts: " << energy_points_ << std::endl;
	std::cout << "attack_damage_: " << attack_damage_ << std::endl;
}