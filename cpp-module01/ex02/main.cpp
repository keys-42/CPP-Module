#include <iostream>
#include <string>

int main()
{
		std::string str("HI THIS IS BRAIN");
		std::string *ptr = &str;
		std::string& ref = str;

		std::cout << "str addr: " << &str << std::endl;
		std::cout << "ptr addr: " << ptr << std::endl;
		std::cout << "ref sddr: " << &ref << std::endl;

		std::cout << "str variable: " << str << std::endl;
		std::cout << "ptr variable: " << *ptr << std::endl;
		std::cout << "ref variable: " << ref << std::endl;
		
	return 0;
}
