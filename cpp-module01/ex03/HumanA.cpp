#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& w)
	: name_(name)
	, w_(&w){};

HumanA::~HumanA() {}

void HumanA::attack() const {
	std::cout << name_ << " attacks with their " << w_->getType() << std::endl;
}
