#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
# define N 5

int main()
{
	int i = 0;
	Animal* a[N];

	while(i < N)
	{
		if (i < 50)
			a[i] = new Dog();
		else
			a[i] = new Cat();
		i++;
	}

	i = 0;
	while(i < N)
	{
		delete a[i];
		i++;
	}
	
	return 0;
}
