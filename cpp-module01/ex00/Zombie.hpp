#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void announce(void);
		void setName(std::string n);
	private:
		std::string name_;
};

void randomChump(std::string n);
Zombie*	newZombie(std::string n);
#endif

