#include "BitcoinExchange.hpp"

void BitcoinExchange::initDatabase(std::string file) {

    std::ifstream f(file.c_str());
    if (!f) throw std::runtime_error("Error: could not open database.");
    std::string line;
    getline(f, line);
    if(line.compare(DATABASEFORMAT)) throw std::runtime_error("Error: database format");
    while (getline(f, line)) { insertFromString(line); }
    f.close();
}

void BitcoinExchange::insertFromString(const std::string& input) {
    std::istringstream ss(input);
    int year, month, day;
    double value;
    char dash, comma;

    ss >> year >> dash >> month >> dash >> day >> comma >> value;
    
    if (ss.fail() || dash != '-' || comma != DATABASEDELIMITER || !ss.eof()) {
        throw std::runtime_error("Error: database format");
    }
    if( ! validateYear(year) || ! validateMonth(month) || ! validateDay(day)) {
        std::stringstream ss;
        ss << "Error: year, month or day out of range." << year << "-" << month << "-" << day;
        throw std::runtime_error(ss.str());
    }
    insertData(year, month, day, value);
}

void BitcoinExchange::insertData( int year, int month, int day, double value) {
    data_[year][month][day] = value;
}

double  BitcoinExchange::findDataCloseTo(int year, int month, int day) {
    int findYear = year;
    int findMonth = month;
    int findDay = day;

    for (; findYear >= MINYEAR; --findYear) {
        BitCoinMap::iterator yearIt = data_.find(findYear);
        if (yearIt != data_.end()) {
            for (; findMonth >= MINMONTH; --findMonth) {
                MonthMap::iterator monthIt = yearIt->second.find(findMonth);
                if (monthIt != yearIt->second.end()) {
                    for (; findDay >= MINDAY; --findDay) {
                        DayMap::iterator dayIt = monthIt->second.find(findDay);
                        if (dayIt != monthIt->second.end()) {
                            return dayIt->second;
                        }
                    }
                    findDay = MAXDAY;
                }
            }
            findMonth = MAXMONTH;
        }
    }

    throw std::runtime_error("Insufficient data. Please add more data.");
    return 0;
}


double  BitcoinExchange::getBitcoinExchangeRate(int year, int month, int day) {
    if (data_[year][month].find(day) == data_[year][month].end()) {
        return findDataCloseTo(year, month, day);
    }
    return data_[year][month][day];
}
