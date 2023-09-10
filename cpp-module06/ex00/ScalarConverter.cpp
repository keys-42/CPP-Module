#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &str) {

    try {
        std::cout << "char: ";
        convert_char(str);
    } catch (ScalarConverter::EmptyStringException &e) {
        std::cout << e.what();
    } catch (ScalarConverter::NonDisplayableException &e) {
        std::cout << e.what();
    } catch (ScalarConverter::EncodingException &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
    try {
        std::cout << "int: ";
        convert_int(str);
    } catch (ScalarConverter::EmptyStringException &e) {
        std::cout << e.what();
    } catch (ScalarConverter::EncodingException &e) {
        std::cout << e.what();
    }

    std::cout << std::endl;
    try {
        std::cout << "float: ";
        convert_float(str);
    } catch (ScalarConverter::EmptyStringException &e) {
        std::cout << e.what();
    } catch (ScalarConverter::EncodingException &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;

    try {
        std::cout << "double: ";
        convert_double(str);
    } catch (ScalarConverter::EmptyStringException &e) {
        std::cout << e.what();
    } catch (ScalarConverter::EncodingException &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}


void ScalarConverter::convert_char(std::string const &str) {
    char c;

    if(str.empty())
        throw ScalarConverter::EmptyStringException();    
    throw ScalarConverter::NonDisplayableException();
    throw ScalarConverter::EncodingException();
    std::cout << c;
}

void ScalarConverter::convert_int(std::string const &str) {
    int number;

    if(str.empty())
        throw ScalarConverter::EmptyStringException();
    throw ScalarConverter::EncodingException();
    
    std::stringstream ss;
    ss << number;
    std::cout << ss.str();
}

void ScalarConverter::convert_float(std::string const &str) {
    if(str.empty())
        throw ScalarConverter::EmptyStringException();
    
    char *end;
    double d_number = strtod(str.c_str(), &end);
    if(*end != '\0')
        throw ScalarConverter::EncodingException();
    
    std::cout << (float)d_number;
}

void ScalarConverter::convert_double(std::string const &str) {
    if(str.empty())
        throw ScalarConverter::EmptyStringException();

    char *end;
    double d_number = strtod(str.c_str(), &end);
    if(*end != '\0')
        throw ScalarConverter::EncodingException();
    std::cout << d_number;
}