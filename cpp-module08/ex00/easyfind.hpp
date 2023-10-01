#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class NotFoundException : public std::exception {
public:
  virtual const char *what() const throw() {
    return "Number was not found in the container.";
  }
};

template <typename T> void easyfind(T container, int n) {
  typename T::iterator result =
      std::find(container.begin(), container.end(), n);
  if (result == container.end()) {
    throw NotFoundException();
  } else {
    std::cout << "found" << std::endl;
  }
}

#endif