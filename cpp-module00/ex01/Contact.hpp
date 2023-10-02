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
	bool getFlag() const;
	void getContants();
	void displayInfo() const;

private:
	bool f;
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;
	static std::string changeContent(std::string s);
};

#endif
