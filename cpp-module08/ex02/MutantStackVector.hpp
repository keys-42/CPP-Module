#ifndef MUTANTSTACKVECTOR_HPP
#define MUTANTSTACKVECTOR_HPP

#include <iostream>
#include <stack>
#include <string>
#include <vector>

// The internal container uses std::vector.
template <typename T>
class MutantStackVector : public std::stack<T, std::vector<T>> {
public:
  MutantStackVector() : std::stack<T, std::vector<T>>() {}
  MutantStackVector(MutantStackVector const &other)
      : std::stack<T, std::vector<T>>(other) {}
  ~MutantStackVector() {}
  MutantStackVector &operator=(MutantStackVector const &other) {
    if (this != &other)
      std::stack<T, std::vector<T>>::operator=(other);
    return *this;
  }
  operator std::stack<T, std::vector<T>>() const {
    return std::stack<T, std::vector<T>>(this->c);
  }

  typedef
      typename std::stack<T, std::vector<T>>::container_type::iterator iterator;
  typedef typename std::stack<T, std::vector<T>>::container_type::const_iterator
      const_iterator;
  iterator begin() { return this->c.begin(); }
  const_iterator begin() const { return this->c.begin(); }
  iterator end() { return this->c.end(); }
  const_iterator end() const { return this->c.end(); }
  void print() {
    for (iterator it = this->c.begin(); it != this->c.end(); ++it)
      std::cout << *it << std::endl;
  }
};

#endif