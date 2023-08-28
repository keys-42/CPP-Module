#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
# define N 5

int main()
{
	Animal* a, * b;

	a = new Dog();
	b = new Cat();
	std::cout << a->getType() << " " << std::endl;
	std::cout << b->getType() << " " << std::endl;

	a->makeSound();
	b->makeSound();
	
	delete(a);
	delete(b);
	return 0;
}
