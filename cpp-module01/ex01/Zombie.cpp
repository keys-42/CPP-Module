#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name_(name) {}

void Zombie::setName(std::string name) { name_ = name; };

void Zombie::announce() {
  std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() { std::cout << this->name_ << ": ~Zombie" << std::endl; }
