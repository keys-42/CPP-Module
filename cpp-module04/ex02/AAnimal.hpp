#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include "Brain.hpp"
#include <iomanip>
#include <iostream>
#include <string>

class AAnimal {
protected:
	std::string type_;

public:
	AAnimal();
	AAnimal(std::string name);
	AAnimal(const AAnimal& a);
	virtual ~AAnimal();
	AAnimal& operator=(const AAnimal& r);
	const std::string& getType(void) const;
	virtual void makeSound(void) const = 0;
};

#endif
