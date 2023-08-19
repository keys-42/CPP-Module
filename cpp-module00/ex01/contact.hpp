#ifndef _CONTACT_HPP
# define _CONTACT_HPP
#include <string>
#include <iostream>

class Contact
{
  public:
	Contact();
	~Contact();
	void set();
	void get();
	bool get_flag();
	std::string get_contents();

  private:
	bool 	f;
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
  	std::string phone_number_;
	std::string darkest_secret_;
};

#endif
