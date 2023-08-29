#include "Weapon.hpp"

Weapon::Weapon(const std::string s) : type_ (s) {}

Weapon::~Weapon(){};

const std::string& Weapon::getType() const { return type_; }

void Weapon::setType(const std::string& new_type) { type_ = new_type; }


