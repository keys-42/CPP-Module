#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class Rpn
{
    private:
        std::stack<std::string> stack;
    public:
        // MutantStack() : std::stack<T>() {}
        // MutantStack(MutantStack const &other) : std::stack<T>(other) {}
        // virtual ~MutantStack() {}
        // MutantStack &operator=(MutantStack const &other) {
        //     if (this != &other)
        //         std::stack<T>::operator=(other);
        //     return *this;
        // }
        // typedef typename std::stack<T>::container_type::iterator iterator;
        // typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        // iterator begin() { return this->c.begin(); }
        // const_iterator begin() const { return this->c.begin(); }
        // iterator end() { return this->c.end(); }
        // const_iterator end() const { return this->c.end(); }
        // void print() {
        //     for (iterator it = this->c.begin(); it != this->c.end(); ++it)
        //         std::cout << *it << std::endl;
        // }
};

#endif