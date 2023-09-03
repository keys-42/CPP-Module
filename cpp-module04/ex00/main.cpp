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
	std::cout << std::setw(5) << "Animal:" << meta->getType() << " " << std::endl;
	std::cout << std::setw(5) << "Dog   :" << j->getType() << " " << std::endl;
	std::cout << std::setw(5) << "Cat   :" << i->getType() << " " << std::endl;
	std::cout << "--------sound--------------" << std::endl;
	meta->makeSound();
	i->makeSound(); 
	j->makeSound();
	std::cout << "---------------------------" << std::endl;

	const WrongAnimal* meta1 = new WrongAnimal();
	const WrongAnimal* i1 = new WrongCat();
	std::cout << "-----------type-------------------" << std::endl;
	std::cout << std::setw(5) << "Animal:" << meta->getType() << " " << std::endl;
	std::cout << std::setw(5) << "Cat   :" << i->getType() << " " << std::endl;
	std::cout << "-----------sound-------------------" << std::endl;
	meta->makeSound();
	i->makeSound(); 
	std::cout << "------------type------------------" << std::endl;
	std::cout << "WrongAnimal :" <<  meta1->getType() << " " << std::endl;
	std::cout << std::setw(5) << "WrongCat    :" <<  i1->getType() << " " << std::endl;
	std::cout << "-----------sound-------------------" << std::endl;
	meta1->makeSound();
	i1->makeSound();
	std::cout << "-------------test-------------" << std::endl;
	const WrongCat  p = WrongCat();
	p.makeSound();
	std::cout << "----------------------------------" << std::endl;

	return 0;
}