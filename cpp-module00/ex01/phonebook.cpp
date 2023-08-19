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
				
void Phonebook::search()
{
	int i;

	i = 0;
	while(i < 8)
	{
		if(contact_[i].get_flag() == false)
			break;
		std::cout << i << " " << contact_[i].get_contents() << std::endl;
		i++;
	}
}
