#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &str) {

    std::string arr[] = {"cahr: ", "int: ", "float: ", "double: " };
    typedef void (*FuncPtr)(const std::string &);

    FuncPtr fcPtr[] = { 
        ScalarConverter::convert_char, 
        ScalarConverter::convert_int, 
        ScalarConverter::convert_float,
        ScalarConverter::convert_double
    };

    for( int i = 0; i < 4; i++) {
        try {
            std::cout << arr[i];
            fcPtr[i](str);
        } catch (ScalarConverter::EmptyStringException &e) {
            std::cout << e.what();
        } catch (ScalarConverter::NonDisplayableException &e) {
            std::cout << e.what();
        } catch (ScalarConverter::EncodingException &e) {
            std::cout << e.what();
        } catch ( ScalarConverter::PositiveInfinityException &e) {
            std::cout << e.what();
            if(arr[i].compare("float: ") == 0)
                std::cout << 'f';
        } catch ( ScalarConverter::NegativeInfinityException &e) {
            std::cout << e.what();
            if(arr[i].compare("float: ") == 0)
                std::cout << 'f';
        } catch ( ScalarConverter::NotANumberException &e) {
            std::cout << e.what();
        }
        std::cout << std::endl;
    }
}


void ScalarConverter::convert_char(std::string const &str) {
    if(str.empty())
        throw ScalarConverter::EmptyStringException();
    char c = toChar(str);

    std::cout << '\'' << c << '\'';
}

char ScalarConverter::toChar(std::string const &str) {
    if(str.length() == 1)
    {
        if(! isprint(str[0]) || isdigit(str[0]))
            throw ScalarConverter::NonDisplayableException();
        return str[0];
    }
    int num = toInt(str);
    if(!isprint(num))
        throw ScalarConverter::NonDisplayableException();

    return static_cast<char>(num);
}

void ScalarConverter::convert_int(std::string const &str) {
    int number;

    if(str.empty())
        throw ScalarConverter::EmptyStringException();
    number = toInt(str);
    std::cout << number;
}

int ScalarConverter::toInt(std::string const &str) {
    double numd = toDouble(str);
    int num = static_cast<int>(numd);
    return num;
}

void ScalarConverter::convert_float(std::string const &str) {
    int precision = 0;
    bool flag = false;
    if(str.empty())
        throw ScalarConverter::EmptyStringException();
    else if(str.compare("+inf") == 0)
        throw ScalarConverter::PositiveInfinityException();
    else if(str.compare("-inf") == 0)
        throw ScalarConverter::NegativeInfinityException();
    else if(str.compare("nan") == 0)
        throw ScalarConverter::NotANumberException();

    float numd = toFloat(str);
    for(std::size_t i =0; i < str.length(); i++) {
        if(flag)
            precision++;
        if(!flag && str[i] == '.')
            flag = true;
    }
    if(precision && str[str.size() - 1] == 'f')
        --precision;
    if(precision == 0)
        precision = 1;
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << numd << 'f';
    
}

float ScalarConverter::toFloat(std::string const &str) {
    double numd = toDouble(str);
    float numf = static_cast<float>(numd);
    return numf;
}


void ScalarConverter::convert_double(std::string const &str) {
    int precision = 0;
    bool flag = false;

    if(str.empty())
        throw ScalarConverter::EmptyStringException();
    else if(str.compare("+inf") == 0)
        throw ScalarConverter::PositiveInfinityException();
    else if(str.compare("-inf") == 0)
        throw ScalarConverter::NegativeInfinityException();
    else if(str.compare("nan") == 0)
        throw ScalarConverter::NotANumberException();
         
    double numd = toDouble(str);
    for(std::size_t i =0; i < str.length(); i++) {
        if(flag)
            precision++;
        if(!flag && str[i] == '.')
            flag = true;
    }
    if(precision && str[str.size() - 1] == 'f')
        --precision;
    if(precision == 0)
        precision = 1;
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << numd;
}

double ScalarConverter::toDouble(std::string const &str) {
    char comma = '.';
    int hasComma = 0;
    
    for (std::size_t i = 0; i < str.size(); ++i) {
        if(i == (str.size()- 1) && str[i] == 'f')
            break;
        if(str[i] == comma) {
            ++hasComma;
            continue;
        }
        if (!isdigit(static_cast<unsigned char>(str[i]))) {
            throw ScalarConverter::EncodingException();
        }
    }
    std::string s = str;
    if(str[str.size() -1 ] == 'f')
        s = str.substr(0,str.size() - 1);
    std::istringstream ss(s);
    double numd;
    ss >> numd;
    return numd;
}
