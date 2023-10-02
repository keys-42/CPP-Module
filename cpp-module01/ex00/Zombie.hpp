#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
public:
	Zombie();
	explicit Zombie(const std::string& name);
	~Zombie();
	void announce(void) const;

private:
	std::string name_;
};

void randomChump(std::string n);
Zombie* newZombie(std::string n);
#endif
