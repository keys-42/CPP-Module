#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
#include <stdlib.h>
# include <string>
#include <stdbool.h>
#include <iomanip>

class Contact
{
  public:
	Contact();
	~Contact();
  void init(void);
  void ser();
  void privacy();

  private:
  std::string arr_[5];
};

class Phonebook
{
  public:
	Phonebook();
	~Phonebook();
  void f_exit();
  void add();
  void f_search();

  private:
  Contact contact_[8];
  int start_;
  int front_;
  int end_;
};

#endif
