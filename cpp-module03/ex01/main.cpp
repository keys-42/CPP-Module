#include "ScavTrap.hpp"

int main() {
  ScavTrap a("Emily"), b("James");
  a.guardGate();
  b.guardGate();
  a.getInfo();
  b.getInfo();

  a.attack(b.getName());
  b.takeDamage(a.getAttackDamage());
  b.beRepaired(5);

  a.getInfo();
  b.getInfo();

  b.attack(a.getName());
  a.takeDamage(b.getAttackDamage());
  a.beRepaired(100);
  a.getInfo();
  b.getInfo();

  while (b.checkPoints()) {
    a.attack(b.getName());
    b.takeDamage(a.getAttackDamage());
  }
  b.attack(a.getName());
  a.beRepaired(100);

  std::cout << "--------------------------------" << std::endl;
  a.getInfo();
  b.getInfo();
  std::cout << "Challenge." << std::endl;
  b.attack(a.getName());
  std::cout << "Challenge end." << std::endl;
  a.getInfo();
  b.getInfo();
  std::cout << "--------------------------------" << std::endl;
  ScavTrap c("Emma"), d("William");
  d.beRepaired(10000000);
  c.getInfo();
  d.getInfo();
  while (c.checkPoints()) {
    c.attack(d.getName());
    d.takeDamage(c.getAttackDamage());
  }
  c.getInfo();
  d.getInfo();
  std::cout << "Challenge." << std::endl;
  c.attack(d.getName());
  c.beRepaired(10000);
  std::cout << "Challenge end." << std::endl;
  c.getInfo();
  d.getInfo();
  a.guardGate();
  b.guardGate();
  c.guardGate();
  d.guardGate();
  return 0;
}
