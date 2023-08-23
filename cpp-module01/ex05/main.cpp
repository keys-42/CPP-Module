#include <iostream>
#include "Harl.hpp"

int main()
{
		std::string s;
		Harl h;

		do{
				std::cout << "level: ";
				std::cin >> s;
				h.complain(s);
    	} while (s.compare("exit"));

		return 0;
}
