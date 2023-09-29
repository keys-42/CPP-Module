#include "BitcoinExchange.hpp"

bool isValidDate(int year, int month, int day) {
    if (year < MINYEAR || MAXYEAR < year) 
        return false;
    if (month < MINMONTH || MAXMONTH < month)
        return false;
    if (day < MINDAY || MAXDAY < day)
        return false;
     
   bool isLeap = false;
    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0) {
            isLeap = true;
        }
    }
    if(month == 2) {
        return (isLeap && day <= 29) || (!isLeap && day <= 28);
    } else if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
        return day <= 30;
    } else {
        return day <= MAXDAY;
    }
}

std::string getDelimiter(const std::string& line, const std::string& front, const std::string& back) {
    if (line.substr(0, front.size()) == front && 
        line.substr(line.size() - back.size(), back.size()) == back) {
        return line.substr(front.size(), line.size() - front.size() - back.size());
    }
    throw std::logic_error("No valid delimiter found or the string format is incorrect.");
}

void getValueAndDate(std::string line,std::string& date, std::string& rate,std::string delimiter)
{
    size_t pos = line.find(delimiter);

    date = line.substr(0, pos);
    if(line.size() > (date.size() + delimiter.size()))
        rate = line.substr(pos + delimiter.length());
    else
        rate = "";
}

bool makeBitcoinExchange(BitcoinExchange& btc) {

    try {
        btc.initDatabase(DATABASE);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
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

void tryExchange(std::string line, BitcoinExchange& btc) {
    std::istringstream ss(line);
    int year, month, day;
    long double value;
    char dash, dash2, pipe;

    ss >> year >> dash >> month >> dash2 >> day >> std::ws >> pipe >> std::ws >> value;

    if (ss.fail()) {
        throw std::logic_error("Error: invalid number format or out of range => " + line);
    }
    if (dash != '-' || dash2 != '-' || pipe != '|' || !ss.eof()) {
        throw std::invalid_argument("Error: bad input => " + line);
    }
    if(value > 1000.0) {
        throw std::out_of_range("Error: too large a number.");
    }
    if(value < 0.0) {
        throw std::out_of_range("Error: not a positive number.");
    }
    if ( !isValidDate(year, month, day)) {
        std::stringstream ss;
        ss << "Error: year, month or day out of range." << year << "-" << month << "-" << day;
        throw std::out_of_range(ss.str());
    }
    double rate = btc.getBitcoinExchangeRate(year,month,day);
    double newValue = rate * static_cast<double>(value);
    output(dash, year, month, day, value, newValue);
}

bool convert(char *file, BitcoinExchange& btc) {
    try {
        FileGuard f(file);
        std::string line;
        getline(f.getStream(), line);
        if(line.compare(INPUTFORMAT) != 0) throw std::logic_error("Error: Input file format");
        while (getline(f.getStream(), line)) {
            try {
                tryExchange(line, btc);
            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return false;
    }
    return true;
}

int main( int argc, char **argv)
{
    if( argc != 2 ) {
        std::cout << "Usage: " << argv[0] << " file" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    if( ! makeBitcoinExchange(btc) ) {
        return 1;
    }
    if( ! convert(argv[1], btc) ) {
        return 1;
    }
    return 0;
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q btc");
// }
