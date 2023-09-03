#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# define N 100

class Brain
{
    private:
        std::string ideas[N];

    public:
        Brain();
        Brain(const Brain & b);
        ~Brain();
        Brain & operator= ( const Brain & r);
        void setIdea(int index, std::string idea);
        const std::string& getIdea(int index) const;
};

#endif