#include "PhoneBook.hpp"

Contact::Contact() : f(false), first_name_(""), last_name_(""), nickname_(""), phone_number_(""), darkest_secret_(""){}

Contact::~Contact() {}
void Contact::set() {

	first_name_ = get_line("Please enter first name			"
						   "	:");
	last_name_ = get_line("Please enter last name 			"
						  "	:");
	nickname_ = get_line("Please enter last nickname 			:");
	for (;;) {
		phone_number_ = get_line("Please enter last phone number	 		:");
		bool all_digits = true;

		for (std::size_t i = 0; i < phone_number_.size(); ++i) {
			if (!std::isdigit(static_cast<unsigned char>(phone_number_[i]))) {
				all_digits = false;
				break;
			}
		}

		if (all_digits)
			break;
		else
			std::cout << phone_number_ << " is not valid. Please enter only numerical values."
					  << std::endl
					  << std::endl;
	}

	darkest_secret_ = get_line("Please enter last darkest secret 		:");
	f = true;
}

bool Contact::getFlag() const {
	return f;
}

std::string Contact::changeContent(std::string s) {
	if (s.length() <= 10)
		return s;
	return s.substr(0, 9) + ".";
}

void Contact::getContants() {
	std::cout << std::setw(10) << changeContent(first_name_) << "|" << std::setw(10)
			  << changeContent(last_name_) << "|" << std::setw(10) << changeContent(nickname_)
			  << "|" << std::endl;
}

void Contact::displayInfo() const {
	std::cout << "first name		:" << first_name_ << std::endl;
	std::cout << "last name		:" << last_name_ << std::endl;
	std::cout << "nickname		:" << nickname_ << std::endl;
	std::cout << "phone number		:" << phone_number_ << std::endl;
	std::cout << "darkest secret		:" << darkest_secret_ << std::endl;
}
