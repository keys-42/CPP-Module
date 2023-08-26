#include "Zombie.hpp"
# define N 10

int main()
{
	Zombie *z = zombieHorde(N, "Foo");
	
	for(int i = 0; i < N; i++){
		std::cout << "index : " << i << ": ";
		z[i].announce();
	}
	delete[] z;
	return 0;
}
