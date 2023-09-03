#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain Default constructor called" << std::endl;
    for (int i = 0; i < N; i++) this->ideas[i] = "no idea";
}

Brain::Brain(const Brain & b) { *this = b; }

Brain & Brain::operator= ( const Brain & r)
{
    for (int i = 0; i < N; i++) this->ideas[i] = r.ideas[i];
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain Default destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea) { this->ideas[index] = idea; }

const std::string& Brain::getIdea(int index) const { return this->ideas[index]; }