#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : hit_points_(10), energy_points_(10), attack_damage_(0), name_(name)
{
	std::cout << "CrapTrap defualt constructor called: " << name <<std::endl;
}

ClapTrap::ClapTrap(std::string name, long long hp, long long ep, long long ad) : hit_points_(hp), energy_points_(ep), attack_damage_(ad), name_(name)
{
	std::cout << "CrapTrap defualt constructor called: " << name <<std::endl;
}

ClapTrap::~ClapTrap(){ std::cout << "ClapTrap defualt destructor called" <<std::endl; }


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