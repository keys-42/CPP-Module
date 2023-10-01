#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

enum LiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
};

class ScalarConverter {
private:
	ScalarConverter(){};
	static LiteralType getLiteralType(std::string const& str);
	static void char_literal(std::string const& str);
	static void int_literal(std::string const& str);
	static void float_literal(std::string const& str);
	static void double_literal(std::string const& str);
	static void pseudo_literal(std::string const& str);

public:
	static void convert(std::string const& str);

	class InvalidException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif