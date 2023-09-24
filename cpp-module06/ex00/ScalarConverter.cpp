#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &str) {
    LiteralType types[] = { 
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        PSEUDO,
    };

    typedef void (*FuncPtr)(const std::string &);
    FuncPtr fcPtr[] = { 
        ScalarConverter::char_literal,
        ScalarConverter::int_literal, 
        ScalarConverter::float_literal,
        ScalarConverter::double_literal,
        ScalarConverter::pseudo_literal,
    };

    try {
        LiteralType type = getLiteralType(str);
        for (int i=0; i < 5; ++i) {
            if (types[i] == type) {
                fcPtr[i](str);
                break;
            }
        }
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}

LiteralType ScalarConverter::getLiteralType(std::string const &str) {
    if(str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return CHAR;

    size_t i=0;
    int hasDot=0;
    int hasf=0;
    int invallidFlag = false;
    
    if(str[i] == '+' || str[i] == '-') ++i;

    for ( ; i < str.length(); ++i ) {
        if (str[i] == '.') ++hasDot;
        else if (str[i] == 'f') ++hasf;
        else if (!std::isdigit(str[i])) invallidFlag = true;
    }

    if( invallidFlag ) {
        if (!str.compare("+inf") || \
            !str.compare("+inff") || \
            !str.compare("-inf") || \
            !str.compare("-inff") || \
            !str.compare("nan") || \
            !str.compare("nanf")) {
            return PSEUDO;
        } else {
            throw ScalarConverter::InvalidException();
        }
    }

    if(hasDot > 1 || hasf > 1) throw ScalarConverter::InvalidException();
    if(hasDot == 1 && hasf == 0) return DOUBLE;
    if(hasDot == 1 && hasf == 1) return FLOAT;
    
    return INT;
}


void ScalarConverter::char_literal(std::string const &str) {
    std::cout << "char   : " << "'" << static_cast<char>(str[0]) << "'" << std::endl;
    std::cout << "int    : " << static_cast<int>(str[0]) << std::endl;
    std::cout << "flaot  : " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "double : " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void ScalarConverter::int_literal(std::string const &str) {
    int number = 0;
    try {
        number = std::stoi(str);
    } catch ( std::exception & e) {
        throw ScalarConverter::InvalidException();
    }
    
    if(std::isprint(number))
        std::cout << "char   : " << "'" << static_cast<char>(number) << "'" << std::endl;
    else if(0 <= number && number <= 127)
        std::cout << "char   : " << "Non displayable" << std::endl;
    else
        std::cout << "char   : " << "impossible" << std::endl;
    
    std::cout << "int    : " << number << std::endl;

    std::ostringstream sfloat, sdouble;
    sfloat << static_cast<float>(number);
    sdouble<< static_cast<double>(number);

    std::string str_float = sfloat.str();
    std::string str_double = sdouble.str();

    if (str_float.find('e') == std::string::npos && str_float.find('E') == std::string::npos) {
        str_float += ".0f";
    }

    if (str_double.find('e') == std::string::npos && str_double.find('E') == std::string::npos) {
        str_double += ".0";
    }

    std::cout << "flaot  : " << str_float << std::endl;
    std::cout << "double : " << str_double << std::endl;
}

void ScalarConverter::float_literal(std::string const &str) {
    float number = 0.0f;
    try {
        number = std::stof(str);
    } catch ( std::exception & e) {
        throw ScalarConverter::InvalidException();
    }


    if(std::isprint(number))
        std::cout << "char   : " << "'" << static_cast<char>(number) << "'" << std::endl;
    else if(0 <= number && number <= 127)
        std::cout << "char   : " << "Non displayable" << std::endl;
    else
        std::cout << "char   : " << "impossible" << std::endl;

    std::cout << "int    : " << static_cast<int>(number) << std::endl;
    if (number == static_cast<int>(number)) {
        std::cout << "float  : " << number << ".0f" << std::endl;
        std::cout << "double : " << static_cast<double>(number) << ".0" << std::endl;
    } else {
        std::cout << "float  : " << number << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(number) << std::endl;
    }
}

void ScalarConverter::double_literal(std::string const &str) {
    double number = 0.0;
    try {
        number = std::stod(str);
    } catch ( std::exception & e) {
        throw ScalarConverter::InvalidException();
    }

    if(std::isprint(number))
        std::cout << "char   : " << "'" << static_cast<char>(number) << "'" << std::endl;
    else if(0 <= number && number <= 127)
        std::cout << "char   : " << "Non displayable" << std::endl;
    else
        std::cout << "char   : " << "impossible" << std::endl;

    std::cout << "int    : " << static_cast<int>(number) << std::endl;

    if (number == static_cast<int>(number)) {
        std::cout << "flaot  : " << static_cast<float>(number) << ".0f" << std::endl;
        std::cout << "double : " << number << ".0" << std::endl;
    } else {
        std::cout << "flaot  : " << static_cast<float>(number) << "f" << std::endl;
        std::cout << "double : " << number << std::endl;
    }
}

void ScalarConverter::pseudo_literal(std::string const&str) {
    std::string s(str);
    std::cout << "char   : " << "impossible" << std::endl;
    std::cout << "int    : " << "impossible" << std::endl;
    if ( s.size() == 5 || !s.compare("nanf") ) {
        s.erase(str.size() - 1);
    }
    std::cout << "flaot  : " << s << "f" << std::endl;
    std::cout << "double : " << s << std::endl;
}

const char* ScalarConverter::InvalidException::what() const throw() {
    return ( "char   : impossible\nint    : impossible\nflaot  : impossible\ndouble : impossible\n");
}
