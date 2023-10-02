#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	explicit FragTrap(const std::string& name);
	virtual ~FragTrap();
	void highFivesGuys() const;
	void attack(const std::string& target);
};

#endif