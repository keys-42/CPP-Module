#include <iostream>
#include <limits>
#include "Harl.hpp"
#include <sstream>
#include <iomanip>

int main()
{
	std::string s;
	Harl h;

	do{
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "| " << \
		std::setw(6) << "DEBUG " <<  "| " << \
		std::setw(6) << " INFO " << "| " << \
		std::setw(6) << "WARNING" << " | " << \
		std::setw(6) << "ERROR " << "|" << \
		std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "level: ";
		if(!std::getline(std::cin, s))
		{
			if(std::cin.eof()){
				std::cin.clear();
				break;
			}
			else {
				std::cin.clear();
				if(std::cin.rdbuf()->in_avail())
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				s.clear();
			}
		}
		h.complain(s);
		std::cout << std::endl;
	} while (s.compare("exit"));

	return 0;
}
