#include "phonebook.hpp"
#include <unistd.h>
#include <sstream>
#include <limits>
#include <fstream>

void order_table()
{
	std::cout << std::endl;
	std::cout << "Please enter the command" << std::endl;
	std::cout << "ADD	: save a new contact" << std::endl;
	std::cout << "SEARCH	: display a specfic contact" << std::endl;
	std::cout << "EXIT" <<std::endl;
	std::cout << "command >";
}

int main()
{
		Phonebook book;
		std::string cmd;

		for(;;)
		{
			order_table();
			if(!(std::cin >> cmd))
			{
				if(std::cin.eof()){
					std::cin.clear();
					return 0;
				}
				else {
					std::cin.clear();
					// std::cin.ignore(10000,'\n');
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cmd.clear();
				}
				sleep(1);
				continue;
			}
			if(cmd.compare("EXIT") == 0)
				break;
			else if(cmd.compare("ADD") == 0)
			{
				book.add();
			}
			else if(cmd.compare("SEARCH") == 0)
			{
				book.search();
			}
			else
			{
				std::cout << "Please enter the correct command!" << std::endl << std::endl;
			}
		}
		return 0;
}


