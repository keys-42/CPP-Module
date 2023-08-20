#include "Zombie.hpp"

void randomChump(std::string n)
{
	Zombie *z;

	z = newZombie(n);
	z->announce();
	delete(z);
}
