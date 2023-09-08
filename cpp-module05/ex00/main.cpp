#include "Bureaucrat.hpp"

int main()
{
	std::cout << "Any attempt to instantiate a Bureaucrat using an invalid grade must throw an ex-ception:" << std::endl;
	{
		Bureaucrat a("test", 1);
		std::cout << a << std::endl;
	}
	{
		Bureaucrat a("test", 100);
		std::cout << a << std::endl;
	}
	{
		Bureaucrat a("test", 150);
		std::cout << a << std::endl;
	}
	{
		Bureaucrat a("test", -1);
		std::cout << a << std::endl;
	}
	{
		Bureaucrat a("test", 0);
		std::cout << a << std::endl;
	}
	{
		Bureaucrat a("test", 151);
		std::cout << a << std::endl;
	}
	std::cout << std::endl << "If the grade is out of range, both of them will throw the same exceptions as the constructor." << std::endl;
	{
		Bureaucrat a("test", 1);
		std::cout << a << std::endl;
		a.upgrade(1);
		a.upgrade(1);
	}
	{
		Bureaucrat a("test", 150);
		std::cout << a << std::endl;
		a.downgrade(1);
		a.downgrade(1);
	}

	return 0;
}

