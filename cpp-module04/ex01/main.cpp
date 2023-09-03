#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "==========================" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "==========================" << std::endl;
	delete j;
	delete i;
	std::cout << "==========================" << std::endl;

	Animal* d = new Dog[2];
	std::cout << "==========================" << std::endl;
	delete[] d;
	std::cout << "==========================" << std::endl;
	Animal* c = new Cat[2];
	std::cout << "==========================" << std::endl;
	delete[] c;
	std::cout << "==========================" << std::endl;
	
	return 0;
}
