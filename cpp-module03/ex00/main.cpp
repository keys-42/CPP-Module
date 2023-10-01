#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Emily"), b("James");
	a.getInfo();
	b.getInfo();

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(5);

	a.getInfo();
	b.getInfo();

	std::cout << "------------------------------------------------------------" << std::endl;

	b.attack(a.getName());
	a.takeDamage(b.getAttackDamage());
	a.beRepaired(100);
	a.getInfo();
	b.getInfo();

	return 0;
}
