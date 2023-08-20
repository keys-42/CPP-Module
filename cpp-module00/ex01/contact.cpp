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

bool Contact::get_flag()
{
	return f;
}

std::string Contact::change_content(std::string s)
{
		std::string ans;

		if(s.length()  < 10){
			std::string space(10 - s.length(), ' ');
			return space + s;
		}

		return s.substr(1,9) + ".";
}

std::string Contact::get_contents()
{
	return "|" + change_content(first_name_) + "|" + change_content(last_name_) + "|" +  change_content(nickname_) + "|";
}

void Contact::display_info()
{
		std::cout << "first name		:" << first_name_ << std::endl;
		std::cout << "last name		:" << last_name_ << std::endl;
		std::cout << "nickname		:" << nickname_ << std::endl;
		std::cout << "phone number		:" << phone_number_ << std::endl;
		std::cout << "darkest secret		:" << darkest_secret_ << std::endl;
}
