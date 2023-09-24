#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <iomanip>
# include <stdexcept>
# include <exception>

enum LiteralType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
};

class ScalarConverter
{
    private:
        static LiteralType getLiteralType(std::string const &str);
        static void char_literal(std::string const &str);
        static void int_literal(std::string const &str);
        static void float_literal(std::string const &str);
        static void double_literal(std::string const &str);
        static void pseudo_literal(std::string const &str);

    public:
        static void convert(std::string const &str);

    class InvalidException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

#endif