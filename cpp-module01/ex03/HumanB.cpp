#include "HumanB.hpp"

HumanB::HumanB(const std::string name): name_(name), w_(NULL){}

HumanB::~HumanB(){};

void HumanB::attack()
{
	std::cout << name_ << " attacks with their " << w_->getType() <<std::endl;
}

void HumanB::setWeapon(Weapon& w) { w_ = &w; }