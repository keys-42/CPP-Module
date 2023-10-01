#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <limits>
#include <vector>

class Span {
private:
	std::vector<int> v_;
	Span();

public:
	Span(unsigned int n);
	Span(const Span& r);
	~Span();
	Span& operator=(const Span& other);

	void checkMaxSize(unsigned int len);
	void addNumber(int number);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void printContainer();

	template<typename T>
	void containerInsert(T v2) {
		checkMaxSize(v2.size());
		v_.insert(v_.end(), v2.begin(), v2.end());
	}
};

class SizeOverFlowException : public std::exception {
public:
	virtual const char* what() const throw() { return "already Max elements stored"; }
};

class SpanException : public std::exception {
public:
	virtual const char* what() const throw() { return "There are no numbers stored, or only one."; }
};

#endif