#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <string>

// The internal container uses std::deque.
template <typename T> class MutantStack : public std::stack<T> {
public:
  MutantStack() : std::stack<T>() {}
  MutantStack(MutantStack const &other) : std::stack<T>(other) {}
  ~MutantStack() {}
  MutantStack &operator=(MutantStack const &other) {
    if (this != &other)
      std::stack<T>::operator=(other);
    return *this;
  }
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  iterator begin() { return this->c.begin(); }
  const_iterator begin() const { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  const_iterator end() const { return this->c.end(); }
  void print() {
    for (iterator it = this->c.begin(); it != this->c.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;
  }
};

#endif