#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
# define A 4

int main()
{
	int i = 0;
	Animal* a[A];

	std::cout << "-------------create--------------" << std::endl;
	while(i < A)
	{
		if (i < (A/2)){
			a[i] = new Dog();
		}
		else
			a[i] = new Cat();
		i++;
	}
	std::cout << "---------------------------------" << std::endl;

	std::cout << "------------deep copy-------------" << std::endl;

	Animal *copyAnimal;
	Brain *ptr1;
	Brain *ptr2;

	copyAnimal = a[0];
	ptr1 = a[0]->getBrain();
	ptr2 = copyAnimal->getBrain();
	std::cout << ptr1->getIdea(0) << std::endl;
	std::cout << ptr2->getIdea(0) << std::endl;
	std::cout << "---------------------------------" << std::endl;
	ptr2->setIdea(0,"new idea");
	std::cout << ptr1->getIdea(0) << std::endl;
	std::cout << ptr2->getIdea(0) << std::endl;

	std::cout << "-------------delete--------------" << std::endl;
	i = 0;
	while(i < A)
	{
		delete a[i];
		i++;
	}
	std::cout << "---------------------------------" << std::endl;
	
	return 0;
}
