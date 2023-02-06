#include "Zombie.hpp"

int main()
{
	Zombie* zom1 = newZombie("first");
	Zombie* zom2 = newZombie("second");
	Zombie zom3;

	zom3.setname("nameeee");
	randomChump("test");
	zom1->announce();
	zom2->announce();
	zom3.announce();
	delete(zom1);
	delete(zom2);

	return 0;
}
