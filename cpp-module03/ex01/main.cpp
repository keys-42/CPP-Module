#include "ScavTrap.hpp"

int main () 
{
	ScavTrap a("Emily"), b("James");

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(5);

	a.getInfo();
	b.getInfo();

	a.guardGate();
	return 0;
}
