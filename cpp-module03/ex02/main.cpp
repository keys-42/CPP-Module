#include "FragTrap.hpp"

int main () 
{
	FragTrap a("Emily"), b("James");

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(5);

	a.getInfo();
	b.getInfo();

	a.highFivesGuys();
	return 0;
}
