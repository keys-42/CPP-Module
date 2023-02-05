#include "phonebook.hpp"

Phonebook::Phonebook()
{
	std::cout << "Phonebook" << std::endl;
	this->end_ = 0;
	this->front_ = 0;
	this->start_ = 0;
}
void Phonebook::f_exit()
{
	std::cout << "EXIT!" << std::endl;
	exit(0);
}

void Phonebook::add()
{
	this->contact_[this->end_ % 8].init();
	this->end_++;
}

void Phonebook::f_search()
{
	int	i;
	int	k;

	i = 0;
	if (this->end_ < 8)
		k = this->end_;
	else
		k = 8;
	while (i < k)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		this->contact_[i].ser();
		i++;
	}
	std::cout << "index :";
	std::cin >> i;
	std::cout << std::right << std::setw(10) << i << "|";
	this->contact_[i].privacy();
}

Phonebook::~Phonebook()
{
	std::cout << "~Phonebook" << std::endl;
}
