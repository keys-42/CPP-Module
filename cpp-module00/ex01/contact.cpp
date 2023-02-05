#include "phonebook.hpp"
Contact::Contact()
{
	std::cout << "Contact" << std::endl;
}
void	print(int index)
{
	if (index == 0)
		std::cout << "name :";
	else if (index == 1)
		std::cout << "last name :";
	else if (index == 2)
		std::cout << "nickname :";
	else if (index == 3)
		std::cout << "phone number :";
	else if (index == 4)
		std::cout << "secret :";
}

void Contact::init(void)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		print(i);
		std::cin >> this->arr_[i];
		i++;
	}
}

void Contact::ser()
{
	int	i;

	i = 0;
	while (i < 3)
	{
		// std::cout.setf(std::ios::right) << std::setw(10) << this->arr_[i] ;
		std::cout << std::right << std::setw(10) << this->arr_[i] << "|";
		i++;
	}
	std::cout << std::endl;
}

void Contact::privacy()
{
	int	i;

	i = 0;
	while (i < 5)
	{
		// std::cout.setf(std::ios::right) << std::setw(10) << this->arr_[i] ;
		std::cout << std::right << std::setw(10) << this->arr_[i] << "|";
		i++;
	}
	std::cout << std::endl;
}

Contact::~Contact()
{
	std::cout << "~Contact" << std::endl;
}
