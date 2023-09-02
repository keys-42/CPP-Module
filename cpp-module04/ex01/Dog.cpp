#include "Dog.hpp"

Dog::Dog( void ) : Animal() { 
	std::cout << "Dog Default constructor called" << std::endl;
    type_ = "Dog";
	brain = new Brain();
	
	std::string arr[N];

	for(int i = 0; i < N; i++){
		arr[i] = "sample idea" + std::to_string(i);
	}

	brain->setIdeas(arr);
}

Dog::~Dog( void ) { 
	delete brain;
	std::cout << "Dog Default destructor called" << std::endl; 
};

void Dog::setBrain(std::string ideas[100])
{
	brain->setIdeas(ideas);
}

Brain *Dog::getBrain() const 
{
	return brain;
}

void Dog::makeSound( void ) const { std::cout << "woof" << std::endl; }

Dog & Dog::operator = ( const Dog & r)
{
	this->brain = r.brain;
	return *this;
}