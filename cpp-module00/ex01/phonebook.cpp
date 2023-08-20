#include "phonebook.hpp"

Phonebook::Phonebook()
{
	std::cout << "new phonebook" << std::endl;
	next_index = 0;
}

Phonebook::~Phonebook()
{
	std::cout << "delete Phonebook" << std::endl;
}

void Phonebook::add()
{
	int i;

	i = get_index();
	contact_[i].set();
	// flush_cin();
}

int Phonebook::get_index()
{
	int ans;

	ans = next_index;
	if(next_index == 7)
		next_index = 0;
	else
		next_index++;
	return ans;
}

int Phonebook::request_index()
{
	std::string str;
	int index;


	try{
		str = get_line("Please enter the index:	 ");
		std::stringstream ss(str);
		ss >> index;
		if (ss.fail() || !ss.eof()) {
			throw std::runtime_error("Invalid string-to-int conversion.");
		}
	}
   	catch(const std::exception& e){
		return -1;
	}
	index--;
	if(0 <= index && index <= 9)
	{
		if(contact_[index].get_flag() == true)
				return index;
	}
	return -1;
}

void Phonebook::display_contact(int index)
{
	contact_[index].display_info();
}

				
void Phonebook::search()
{
	int i;
	int index;

	i = 0;
	while(i < 8)
	{
		if(contact_[i].get_flag() == false)
			break;
		std::cout << i + 1 << " " << contact_[i].get_contents() << std::endl;
		i++;
	}
	index =request_index();
	if(index >= 0)
		display_contact(index);
	else
		std::cout << "Non-existent contact. Please enter the correct index." << std::endl;
}
