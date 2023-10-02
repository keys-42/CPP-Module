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

void randomChump(const std::string& n);
Zombie* newZombie(const std::string& n);
#endif
