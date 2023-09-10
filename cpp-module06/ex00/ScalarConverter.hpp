#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <cstdlib>
#include <iomanip> 

class ScalarConverter
{
    private:
        static void convert_char(std::string const &str);
        static void convert_int(std::string const &str);
        static void convert_float(std::string const &str);
        static void convert_double(std::string const &str);
        static char toChar(std::string const &str);
        static int  toInt(std::string const &str);
        static float toFloat(std::string const &str);
        static double toDouble(std::string const &str);
        
    public:
        static void convert(std::string const &str);

        class EncodingException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return ("impossible"); }
        };

        class NonDisplayableException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return ("Non displayable"); }
        };

        class EmptyStringException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return ("Empty string"); }
        };

        class PositiveInfinityException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return ("+inf"); }
        };
        
        class NegativeInfinityException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return ("-inf"); }
        };

        class NotANumberException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return ("nan"); }
        };
};

#endif