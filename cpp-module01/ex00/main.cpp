#include "Zombie.hpp"

int main()
{
	Zombie* zom1 = newZombie("first");
	Zombie* zom2 = newZombie("second");

	randomChump("test");
	delete(zom1);
	delete(zom2);
	return 0;
}
