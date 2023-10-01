
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
public:
  HumanB(const std::string name);
  ~HumanB();
  void attack();
  void setWeapon(Weapon &w);

private:
  std::string name_;
  Weapon *w_;
};

#endif