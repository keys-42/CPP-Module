#ifndef DATA_HPP
#define DATA_HPP

#include <ctime>
#include <iostream>

struct Data {
  int id_;
  std::string name_;
  std::time_t timestamp_;
};

#endif