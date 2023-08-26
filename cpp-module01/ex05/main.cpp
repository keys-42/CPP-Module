#include <iostream>
#include <limits>
#include "Harl.hpp"
#include <sstream>

int main()
{
	std::string s;
	Harl h;

	do{
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
	} while (s.compare("exit"));

	return 0;
}
