#ifndef _PHONEBOOK_HPP
# define _PHONEBOOK_HPP
# include "contact.hpp"
#include <iostream>

class Phonebook
{
  public:
	Phonebook();
	~Phonebook();
  void add();
  void search();

  private:
  Contact contact_[8];
  int get_index();
  int next_index;
  int request_index();
  void display_contact(int index);
};

#endif
