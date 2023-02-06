#include "Zombie.hpp"

void randomChump(std::string n)
{
	Zombie z;

	z.setname(n);
	z.announce();
}
