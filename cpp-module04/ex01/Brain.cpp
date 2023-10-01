#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain Default constructor called" << std::endl;
  for (int i = 0; i < N; i++)
    this->ideas[i] = "no idea";
}

Brain::Brain(const Brain &b) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = b;
}

Brain &Brain::operator=(const Brain &r) {
  std::cout << "Brain copy assignment operator overload called" << std::endl;
  for (int i = 0; i < N; i++)
    this->ideas[i] = r.ideas[i];
  return *this;
}

Brain::~Brain() { std::cout << "Brain Default destructor called" << std::endl; }
