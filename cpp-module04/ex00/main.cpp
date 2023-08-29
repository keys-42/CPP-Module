#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "----------type-------------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "--------sound--------------" << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();
	std::cout << "---------------------------" << std::endl;

	const WrongAnimal* meta1 = new WrongAnimal();
	const WrongAnimal* i1 = new WrongCat();
	std::cout << "-----------type-------------------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "-----------sound-------------------" << std::endl;
	i->makeSound(); 
	meta->makeSound();
	std::cout << "------------type------------------" << std::endl;
	std::cout << meta1->getType() << " " << std::endl;
	std::cout << i1->getType() << " " << std::endl;
	std::cout << "-----------sound-------------------" << std::endl;
	i1->makeSound();
	meta1->makeSound();
	std::cout << "----------------------------------" << std::endl;

	return 0;
}