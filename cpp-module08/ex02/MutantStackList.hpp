#ifndef MUTANTSTACKLIST_HPP
#define MUTANTSTACKLIST_HPP

#include <iostream>
#include <list>
#include <stack>
#include <string>

// The internal container uses std::list.
template <typename T>
class MutantStackList : public std::stack<T, std::list<T> > {
public:
  MutantStackList() : std::stack<T, std::list<T> >() {}
  MutantStackList(MutantStackList const &other)
      : std::stack<T, std::list<T> >(other) {}
  ~MutantStackList() {}
  MutantStackList &operator=(MutantStackList const &other) {
    if (this != &other)
      std::stack<T, std::list<T> >::operator=(other);
    return *this;
  }
  operator std::stack<T, std::list<T> >() const {
    return std::stack<T, std::list<T> >(this->c);
  }

  typedef
      typename std::stack<T, std::list<T> >::container_type::iterator iterator;
  typedef typename std::stack<T, std::list<T> >::container_type::const_iterator
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