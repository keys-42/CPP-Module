#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : hit_points_(10), energy_points_(10), attack_damage_(0), name_(name)
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

void ClapTrap::takeDamage(unsigned int amount)
{ 
	if( hit_points_ > amount ) 
		hit_points_-= amount;
	else 
		hit_points_ = 0;
	std::cout << "ClapTrap " << this->getName() << " loses " << amount << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{ 
	if(!checkPoints())
		return;
	consumeEnergyPoints();
	hit_points_ += amount;
	std::cout << "ClapTrap " << this->getName() << " repairs itself by " << amount << " points." << std::endl;
}

bool ClapTrap::checkPoints( void ) const 
{
	if( !hit_points_ )
		std::cout << "No hit points for " <<  this->getName() << "."<< std::endl; 
	else if ( !energy_points_ )
		std::cout << "No energy points for " <<  this->getName() << "."<< std::endl; 
	return hit_points_ && energy_points_; 
}

void ClapTrap::getInfo() const 
{ 
	std::cout << name_ << " information " << std::endl;
	std::cout << "{" << std::endl;
	std::cout << "	hit_points: " << hit_points_ << std::endl;
	std::cout << "	energy_ponts: " << energy_points_ << std::endl;
	std::cout << "	attack_damage_: " << attack_damage_ << std::endl;
	std::cout << "}" << std::endl;
}

std::string ClapTrap::getName() const { return name_; }
			
long long ClapTrap::getAttackDamage() const { return attack_damage_; }

void ClapTrap::consumeEnergyPoints( void ) { energy_points_--; }
