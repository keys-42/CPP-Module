#include "PhoneBook.hpp"

Phonebook::Phonebook() {
	next_index = 0;
}

Phonebook::~Phonebook() {}

void Phonebook::add() {
	int i;

	i = get_index();
	contact_[i].set();
}

int Phonebook::get_index() {
	int ans;

	ans = next_index;
	if (next_index == 7)
		next_index = 0;
	else
		next_index++;
	return ans;
}

int Phonebook::request_index() {
	std::string str;
	int index;

	try {
		str = get_line("Please enter the index:	 ");
		std::stringstream ss(str);
		ss >> index;
		if (ss.fail() || !ss.eof()) {
			throw std::runtime_error("Invalid string-to-int conversion.");
		}
	} catch (const std::exception& e) {
		return -1;
	}
	index--;
	if (0 <= index && index <= 8) {
		if (contact_[index].getFlag() == true)
			return index;
	}
	return -1;
}

void Phonebook::display_contact(int index) {
	contact_[index].displayInfo();
}

void Phonebook::search() {
	int i;
	int index;

	i = 0;
	while (i < 8) {
		if (contact_[i].getFlag() == false)
			break;
		std::cout << std::setw(10) << i + 1 << "|";
		contact_[i].getContants();
		i++;
	}
	index = request_index();
	if (index >= 0)
		display_contact(index);
	else
		std::cout << "Non-existent contact. Please enter the correct index." << std::endl;
}
