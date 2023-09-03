#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=================================" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "=================================" << std::endl;
	delete j;
	delete i;
	
	std::cout << "=================================" << std::endl;
    const Animal* a[4] = { 
		new Dog(), 
		new Dog(), 
		new Cat(), 
		new Cat(),
	};

	std::cout << "=================================" << std::endl;
    for ( int i = 0; i < 4; i++ ) { delete a[i]; }
	return 0;
}
