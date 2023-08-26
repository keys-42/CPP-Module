#include "ClapTrap.hpp"

int main () 
{
	ClapTrap a("Emily"), b("James");

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(5);

	a.getInfo();
	b.getInfo();

	return 0;
}
