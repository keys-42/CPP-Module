#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <iostream>
#include <stack>
#include <string>

class Rpn {
	typedef int (Rpn::*CalcPtr)(int, int) const;

private:
	std::stack<int> stack_;
	int sumNumber(int x, int y) const;
	int differenceNumber(int x, int y) const;
	int productNumber(int x, int y) const;
	int quotientNumber(int x, int y) const;

public:
	Rpn();
	Rpn(const Rpn& r);
	virtual ~Rpn();
	Rpn& operator=(const Rpn& other);
	CalcPtr calcPtr[4];
	int stackTop() const;
	void stackPop();
	void stackPush(int n);
	bool isStackEmpty();
	void calc(char c);

	void rpn(const std::string& line);

	void print();
};

#endif