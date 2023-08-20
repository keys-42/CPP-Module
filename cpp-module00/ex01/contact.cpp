#include "phonebook.hpp"

Contact::Contact()
{
	f = false;
	first_name_ = "";
	last_name_= "";
	nickname_ = "";
	phone_number_ = "";
	darkest_secret_ = "";
}

Contact::~Contact(){}
void Contact::set()
{
	std::string tmp;

	first_name_ = get_line( "Please enter first name				:");
	last_name_ = get_line("Please enter last name 				:");
	nickname_ = get_line("Please enter last nickname 			:");
	for (;;) {
		phone_number_ = get_line("Please enter last phone number	 		:");
		bool all_digits = true;

		for (std::string::const_iterator it = phone_number_.begin(); it != phone_number_.end(); ++it) {
			if (!std::isdigit(static_cast<unsigned char>(*it))) {
				all_digits = false;
				break;
			}
		}

		if (all_digits)
			break;
		else
			std::cout << phone_number_ << " is not valid. Please enter only numerical values." << std::endl <<std::endl;
	}

	darkest_secret_ = get_line("Please enter last darkest secret 		:");
	f = true;
}

bool Contact::get_flag()
{
	return f;
}

std::string Contact::change_content(std::string s)
{
	std::string ans;

	if(s.length()  < 10){`
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
