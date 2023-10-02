#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Animal {
protected:
	std::string type_;

public:
	Animal();
	explicit Animal(const std::string& name);
	Animal(const Animal& a);
	virtual ~Animal();
	Animal& operator=(const Animal& r);
	const std::string& getType(void) const;
	virtual void makeSound(void) const;
};

#endif
