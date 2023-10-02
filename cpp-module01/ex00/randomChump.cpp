#include "Zombie.hpp"

void randomChump(const std::string& n) {
	Zombie z = Zombie(n);

	z.announce();
}
