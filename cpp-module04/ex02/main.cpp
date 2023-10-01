#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "10================================" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << "12================================" << std::endl;
	delete j;
	delete i;

	std::cout << "16================================" << std::endl;
	const AAnimal* a[4] = {
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat(),
	};

	std::cout << "24================================" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete a[i];
	}

	std::cout << "27================================" << std::endl;
	{
		Dog dog;
		std::cout << "30================================" << std::endl;
		Dog dog2(dog);
		std::cout << "32================================" << std::endl;
		Dog dog3 = dog;
		std::cout << "34================================" << std::endl;
	}
	return 0;
}
