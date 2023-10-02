#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap {
public:
	explicit ClapTrap(const std::string& name);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	long long getAttackDamage() const;
	bool checkPoints(void) const;
	void consumeEnergyPoints(void);
	void getInfo(void) const;

private:
	std::string name_;
	long long hit_points_;
	long long energy_points_;
	long long attack_damage_;
};

#endif
