#include "Zombie.hpp"

Zombie* newZombie(const std::string& n) {
	return new Zombie(n);
}
