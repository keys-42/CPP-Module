#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &c);
  virtual ~Cat();
  Cat &operator=(const Cat &r);
  void makeSound(void) const;
};

#endif