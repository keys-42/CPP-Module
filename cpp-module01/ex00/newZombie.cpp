#include "Zombie.hpp"

Zombie*	newZombie(std::string n)
{
	Zombie* z = new Zombie;

	z->setname(n);
	return z;
}
