#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <iostream>
#include <stack>
#include <string>

class Rpn {
	typedef int (*CalcPtr)(int, int); 

private:
	std::stack<int> stack_;
	CalcPtr calcPtr[4];
	static int sumNumber(int x, int y);
	static int differenceNumber(int x, int y);
	static int productNumber(int x, int y);
	static int quotientNumber(int x, int y);

public:
	Rpn();
	Rpn(const Rpn& r);
	virtual ~Rpn();
	Rpn& operator=(const Rpn& other);
	int stackTop() const;
	void stackPop();
	void stackPush(int n);
	bool isStackEmpty() const;
	void calc(char c);

	void rpn(const std::string& line);
};

#endif