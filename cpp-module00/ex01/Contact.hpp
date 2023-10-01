#ifndef _CONTACT_HPP
#define _CONTACT_HPP
#include <iomanip>
#include <iostream>
#include <string>

class Contact {
public:
  Contact();
  ~Contact();
  void set();
  bool getFlag();
  void getContants();
  void displayInfo();

private:
  bool f;
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string phone_number_;
  std::string darkest_secret_;
  std::string changeContent(std::string s);
};

#endif
