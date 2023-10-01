#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal {
private:
  Brain *brain;

public:
  Dog();
  Dog(const Dog &d);
  virtual ~Dog();
  Dog &operator=(const Dog &r);
  void makeSound(void) const;
};

#endif