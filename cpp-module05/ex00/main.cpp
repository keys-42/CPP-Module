#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl << "--------simple test-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 1);
			std::cout << a << std::endl;
			Bureaucrat b("test", 100);
			std::cout << b << std::endl;
			Bureaucrat c("test", 150);
            std::cout << c << std::endl;
		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------Initialize: Grade value is too high.[0]-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 0);
			std::cout << a << std::endl;
		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------Initialize: Grade value is too high.[-1]-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", -1);
			std::cout << a << std::endl;
		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------Initialize: Grade value is too low.[151]-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 151);
			std::cout << a << std::endl;
		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test upgrade [++1]-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 5);
			std::cout << a << std::endl;
			while(1)
			{
				a.upgrade(1);
				std::cout << a << std::endl;
			}
		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test downgrade [--1]-------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 145);
			std::cout << a << std::endl;
			while(1)
			{
				a.downgrade(1);
				std::cout << a << std::endl;
			}
		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test [copy constructor] -------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 75);
			std::cout << a << std::endl;
			Bureaucrat b(a);
			std::cout << b << std::endl;
		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test [copy assignment operator overload] -------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 75);
			std::cout << a << std::endl;
			Bureaucrat b ("123456",100);
			std::cout << b << std::endl;
			b = a;
			std::cout << b << std::endl;
		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test upgrade [0] -------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 5);
			std::cout << a << std::endl;
			while(1)
			{
				a.downgrade(0);
				std::cout << a << std::endl;
			}
		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "--------simple test downgrade [-1] -------------------- " << __FILE__ << " in " << __LINE__ << std::endl;
	{
		try {
			Bureaucrat a("test", 5);
			std::cout << a << std::endl;
			while(1)
			{
				a.upgrade(-1);
				std::cout << a << std::endl;
			}
		} catch ( std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q bureaucrat");
// }
