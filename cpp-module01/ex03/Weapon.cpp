#include "Weapon.hpp"

Weapon::Weapon(){};
Weapon::~Weapon(){};

const std::string& Weapon::get_type() const
{
	return type_;
}

void Weapon::set_type(const std::string& new_type)
{
	type_ = new_type;
}


