#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
# include <exception>

class Rpn
{
    typedef int (Rpn::*CalcPtr)(int, int) const ;
    
    private:
        std::stack<int> stack_;
        int sumNumber(int x,int y) const ;
        int differenceNumber(int x, int y) const ;
        int productNumber(int x, int y) const ;
        int quotientNumber(int x, int y) const ;

    public:
        Rpn();
        Rpn(const Rpn & r);
        virtual ~Rpn();
        Rpn & operator= (const Rpn &other);
        CalcPtr calcPtr[4];
        int stackTop() const;
        void stackPop();
        void stackPush(int n);
        void calc(char c);

        void rpn(const std::string &line);

        void print();
        // typedef typename std::stack<T>::containe_type::iterator iterator;
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