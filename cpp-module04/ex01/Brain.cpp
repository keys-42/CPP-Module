#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain Default constructor called" << std::endl; }

Brain::~Brain(){ std::cout << "Brain Default destructor called" << std::endl; }

void Brain::setIdeas(std::string newIdeas[N]) { for(int i = 0; i < N; i++) ideas[i] = newIdeas[i]; }
void Brain::setIdea(int index, std::string idea) { ideas[index] = idea; }

const std::string& Brain::getIdea(int index) const { return ideas[index]; }

Brain & Brain::operator = ( const Brain & r)
{
    for(int i = 0 ; i < 100; i++) {  this->ideas[i] =  r.ideas[i]; }

    return *this;
}
