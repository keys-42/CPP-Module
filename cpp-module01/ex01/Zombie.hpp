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
	void setName(const std::string& name) const;

private:
	std::string name_;
};

Zombie* zombieHorde(int n, const std::string& name);
#endif
