#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
  std::string type_;

public:
  WrongAnimal();
  virtual ~WrongAnimal();
  std::string getType(void) const;
  void makeSound(void) const;
};

#endif