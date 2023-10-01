#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#define N 100

class Brain {
private:
  std::string ideas[N];

public:
  Brain();
  Brain(const Brain &b);
  ~Brain();
  Brain &operator=(const Brain &r);
};

#endif