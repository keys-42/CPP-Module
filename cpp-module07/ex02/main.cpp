#include "Array.hpp"

#define N 5;
#define GREEN "\033[32m"
#define RESET "\033[0m"

int main() {
	{
		try {
			std::cout << GREEN;
			std::cout << std::endl
					  << "--------empty array-------------------- " << __FILE__ << " in "
					  << __LINE__ << std::endl;
			std::cout << RESET;

			Array<int> a;
			std::cout << "operator<< a: [" << a << "]" << std::endl;
			std::cout << "try operator[] index" << std::endl;
			try {
				std::cout << a[0] << std::endl;
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	{
		try {
			std::cout << GREEN;
			std::cout << std::endl
					  << "--------char array-------------------- " << __FILE__ << " in " << __LINE__
					  << std::endl;
			std::cout << RESET;

			Array<char> a(5);
			std::cout << "operator<< a: " << a << std::endl;
			for (unsigned int i = 0; i < a.size(); i++)
				a[i] = i + 66;
			std::cout << "operator<< a: " << a << std::endl;
			std::cout << "try operator[] index" << std::endl;
			try {
				for (unsigned int i = 0; i < 10; ++i) {
					std::cout << a[i] << std::endl;
				}
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	{
		try {
			std::cout << GREEN;
			std::cout << std::endl
					  << "--------std::string array-------------------- " << __FILE__ << " in "
					  << __LINE__ << std::endl;
			std::cout << RESET;

			Array<std::string> a(5);
			std::cout << "operator<< a: " << a << std::endl;
			for (unsigned int i = 0; i < a.size(); i++)
				a[i] = i + 66;
			std::cout << "operator<< a: " << a << std::endl;
			std::cout << "try operator[] index" << std::endl;
			try {
				for (unsigned int i = 0; i < 10; ++i) {
					std::cout << a[i] << std::endl;
				}
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	{
		try {
			std::cout << GREEN;
			std::cout << std::endl
					  << "--------double array-------------------- " << __FILE__ << " in "
					  << __LINE__ << std::endl;
			std::cout << RESET;

			Array<double> a(5);
			std::cout << "operator<< a: " << a << std::endl;
			for (unsigned int i = 0; i < a.size(); i++)
				a[i] = i + M_PI;
			std::cout << "operator<< a: " << a << std::endl;
			std::cout << "try operator[] index" << std::endl;
			try {
				for (unsigned int i = 0; i < 10; ++i) {
					std::cout << a[i] << std::endl;
				}
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	std::cout << std::endl;
	{
		try {
			std::cout << GREEN;
			std::cout << std::endl
					  << "--------simple test-------------------- " << __FILE__ << " in "
					  << __LINE__ << std::endl;
			std::cout << RESET;
			unsigned int n = (unsigned int)N;
			Array<int> a(n);
			Array<int> b(n);
			Array<int> c(a);

			b = a;
			std::cout << "a: " << a << std::endl;
			std::cout << "b: " << b << std::endl;
			std::cout << "c: " << c << std::endl;

			for (unsigned int i = 0; i < a.size(); i++)
				a[i] = i;
			for (unsigned int i = 0; i < a.size(); i++)
				b[i] = i * M_PI;
			for (unsigned int i = 0; i < a.size(); i++)
				c[i] = a[i] * b[i];

			std::cout << GREEN;
			std::cout << std::endl
					  << "a = 0, 1, 2, 3, 4  " << __FILE__ << " in " << __LINE__ << std::endl;
			std::cout << RESET;
			std::cout << "a: " << a << std::endl;

			std::cout << GREEN;
			std::cout << std::endl << "b = a*π  " << __FILE__ << " in " << __LINE__ << std::endl;
			std::cout << RESET;
			std::cout << "b: " << b << std::endl;

			std::cout << GREEN;
			std::cout << std::endl << "c = b * a  " << __FILE__ << " in " << __LINE__ << std::endl;
			std::cout << RESET;
			std::cout << "c: " << c << std::endl;
			std::cout << GREEN;
			std::cout << std::endl
					  << "try operator[] index " << __FILE__ << " in " << __LINE__ << std::endl;
			std::cout << RESET;
			try {
				for (unsigned int i = 0; i < a.size() + 10; ++i) {
					std::cout << a[i] << std::endl;
				}
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q array");
// }