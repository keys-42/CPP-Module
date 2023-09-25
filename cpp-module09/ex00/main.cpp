#include "BitcoinExchange.hpp"

bool validateYear(int year) {
    if (year < MINYEAR || year > MAXYEAR) 
        return false;
    return true;
}

bool validateMonth(int month) {
    if (month < MINMONTH || month > MAXMONTH) 
        return false;
    return true;
}

bool validateDay(int day) {
    if (day < MINDAY || day > MAXDAY) 
        return false;
    return true;
}

std::string getDelimiter(const std::string& line, const std::string& front, const std::string& back) {
    if (line.substr(0, front.size()) == front && 
        line.substr(line.size() - back.size(), back.size()) == back) {
        return line.substr(front.size(), line.size() - front.size() - back.size());
    }
    throw std::runtime_error("No valid delimiter found or the string format is incorrect.");
}

void getValueAndDate(std::string line,std::string *date, std::string *rate,std::string delimiter)
{
    size_t pos = line.find(delimiter);

    *date = line.substr(0, pos);
    if(line.size() > (date->size() + delimiter.size()))
        *rate = line.substr(pos + delimiter.length());
    else
        *rate = "";
}

bool makeBitcoinExchange(BitcoinExchange* btc) {

    try {
        btc->initDatabase(DATABASE);
    } catch (std::runtime_error &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        delete btc;
        return false;
    }
    return true;
}

void output(char dash, int year, int month, int day, double value, double newValue) {
    std::cout  << \
    year << \
    dash << \
    std::setfill('0') << std::setw(2) << month << \
    dash << \
    std::setfill('0') << std::setw(2) << day << \
    " => " << \
    value << \
    " = " << \
    newValue \
    << std::endl;
}

bool doubleOverflow(double x, double y) {
    if (x == 0.0 || y == 0.0) {
        return false;
    }

    double maxVal = std::numeric_limits<double>::max();
    if (std::abs(x) > maxVal / std::abs(y) || std::abs(y) > maxVal / std::abs(x)) {
        return true;
    }
    return false;
}

void tryExchange(std::string line, BitcoinExchange* btc) {
    std::istringstream ss(line);
    int year, month, day;
    long double value;
    char dash, dash2, pipe;

    ss >> year >> dash >> month >> dash2 >> day >> std::ws >> pipe >> std::ws >> value;

    if (ss.fail()) {
        throw std::runtime_error("Error: invalid number format or out of range => " + line);
    }
    if (dash != '-' || dash2 != '-' || pipe != '|' || !ss.eof()) {
        throw std::runtime_error("Error: bad input => " + line);
    }
    if(value > 1000.0) {
        throw std::runtime_error("Error: too large a number.");
    }
    if(value < 0.0) {
        throw std::runtime_error("Error: not a positive number.");
    }
    if( ! validateYear(year) || ! validateMonth(month) || ! validateDay(day) ) {
        std::stringstream ss;
        ss << "Error: year, month or day out of range." << year << "-" << month << "-" << day;
        throw std::runtime_error(ss.str());
    }
    double rate = btc->getBitcoinExchangeRate(year,month,day);
    if( doubleOverflow(rate, value) )
        throw std::runtime_error("Error: rate * value overflows.");
    double newValue = rate * value;
    output(dash, year, month, day, value, newValue);
}

bool convert(char *file,BitcoinExchange* btc) {
    std::ifstream f(file);
    if (!f) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    try {
        std::string line;
        getline(f, line);
        if(line.compare(INPUTFORMAT) != 0) throw std::runtime_error("Error: Input file format");
        std::string date;
        std::string value;
        while (getline(f, line)) {
            try {
                tryExchange(line, btc);
            } catch (std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
            }
        }
        f.close();
    } catch (std::runtime_error &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        f.close();
        delete btc;
        return false;
    }
    return true;

}

int main( int argc, char **argv)
{
    if( argc != 2) {
        std::cout << "Usage: " << argv[0] << " file" << std::endl;
        return 1;
    }
    BitcoinExchange* btc = new BitcoinExchange();
    if( ! makeBitcoinExchange(btc) )
        return 1;
    if( ! convert(argv[1], btc) )
        return 1;

    std::cout << "===================================================" << std::endl;
    std::cout << "====== " << __FILE__ << " in " << __LINE__  << " copy constructor test" << " ======" << std::endl;
    std::cout << "===================================================" << std::endl;

    {
        BitcoinExchange btc2(*btc);
        try {
            btc->findOrFail(2017, 1, 1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            btc2.findOrFail(2017, 1, 1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        btc2.addData(2017, 1, 1, 2017.0101);
        try {
            btc->findOrFail(2017, 1, 1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            btc2.findOrFail(2017, 1, 1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "===================================================" << std::endl;
    std::cout << "== " << __FILE__ << " in " << __LINE__  << " copy assignment operator test" << " ==" << std::endl;
    std::cout << "===================================================" << std::endl;
    {
        BitcoinExchange btc2 = *btc;
        try {
            btc->findOrFail(2017, 1, 1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            btc2.findOrFail(2017, 1, 1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        btc2.addData(2017, 1, 1, 2017.01);
        try {
            btc->findOrFail(2017, 1, 1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            btc2.findOrFail(2017, 1, 1);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    
    delete btc;
    return 0;
}
