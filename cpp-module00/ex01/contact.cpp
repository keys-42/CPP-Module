#include "phonebook.hpp"

Contact::Contact()
{
		std::cout << "new Contact" <<std::endl;
		f = false;
		first_name_ = "";
		last_name_= "";
		nickname_ = "";
		phone_number_ = "";
		darkest_secret_ = "";
}

Contact::~Contact()
{
		std::cout << "delete Contact" << std::endl;
}

void Contact::set()
{
		std::cout << "Please enter first name		:";
		std::cin >> first_name_;
		std::cout << "Please enter last name 		:";
		std::cin >> last_name_;
		std::cout << "Please enter nickname 		:" ;
		std::cin >> nickname_;
		std::cout << "Please enter phone number 	:" ;
		std::cin >> phone_number_;
		std::cout << "Please enter darkest secret 	:";
		std::cin >> darkest_secret_;
		f = true;
}

void Contact::get()
{
		std::cout << "first name is " << first_name_ << std::endl;
		std::cout << "last name is " << last_name_ << std::endl;
		std::cout << "nickname is " << nickname_ << std::endl;
		std::cout << "phone number is " << phone_number_ << std::endl;
		std::cout << "darkest secret is " << darkest_secret_ << std::endl;
}

bool Contact::get_flag()
{
	return f;
}

std::string Contact::get_contents()
{
	return first_name_ + " " + last_name_ + " " + nickname_;
}