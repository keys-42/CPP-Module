#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	explicit ScavTrap(const std::string& name);
	virtual ~ScavTrap();
	void guardGate() const;
	void attack(const std::string& target);
};

#endif
