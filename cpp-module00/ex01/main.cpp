#include "phonebook.hpp"

int	main(void)
{
	Phonebook	book;

	std::string line;
	std::cout << "aaa" << std::endl;
	while (std::getline(std::cin, line))
	{
		if (line == "EXIT")
			book.f_exit();
		else if (line == "ADD")
			book.add();
		else if (line == "SEARCH")
			book.f_search();
	}
}
