#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# define N 100

class Brain
{
	public:
		Brain();
		~Brain();
		void setIdeas(std::string newIdeas[N]);
		void setIdea(int index, std::string idea);
		const std::string& getIdea(int index) const;
        Brain & operator = ( const Brain & r);

    private:
		std::string ideas[N];
};

#endif
