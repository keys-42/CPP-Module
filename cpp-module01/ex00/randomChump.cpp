#include "Zombie.hpp"

void randomChump(std::string n)
{
	Zombie *z = new Zombie(n);

	z->announce();
	delete(z);
}
