#include "Zombie.hpp"

void randomChump(std::string n) {
  Zombie z = Zombie(n);

  z.announce();
}
