#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <exception>
#include <climits>
#include <iomanip>
#include <cmath>
#include <limits>

# define DATABASE "data.csv"
# define DATABASEFORMAT "date,exchange_rate"
# define DATABASEDELIMITER ','
# define INPUTFORMAT  "date | value"
# define INPUTDEDELIMITER " | "
# define MINDAY 1
# define MAXDAY 31
# define MINMONTH 1
# define MAXMONTH 12
# define MINYEAR 2009
# define MAXYEAR 2024

std::string getDelimiter(const std::string& line, const std::string& front, const std::string& back);
void getValueAndDate(std::string line,std::string *date, std::string *rate,std::string delimiter);
bool validateYear(int year);
bool validateMonth(int month);
bool validateDay(int day);

class BitcoinExchange
{
    typedef std::map<int, double> DayMap;
    typedef std::map<int, DayMap> MonthMap;
    typedef std::map<int, MonthMap> BitCoinMap;
    private:
        BitCoinMap data_;
    
    public:
        BitcoinExchange(){};
        // BitcoinExchange(std::map<std::string, std::string> exchangeRates): exchangeRates_(exchangeRates) {}
        BitcoinExchange(BitCoinMap data) : data_(data) {};
        BitcoinExchange(const BitcoinExchange &r) : data_(r.data_) {};
        ~BitcoinExchange() {}
        BitcoinExchange & operator= (const BitcoinExchange &other) {
            if(this != &other)
                this->data_ = other.data_;
            return *this;
        }
        void initDatabase(std::string file);
        void insertData(int year, int month, int day, double value);
        void insertFromString(const std::string& input);
        void printDatabase() {
            for (BitCoinMap::const_iterator yearIt = data_.begin(); yearIt != data_.end(); ++yearIt) {
                int year = yearIt->first;
                std::cout << year << std::endl;
                
                for (MonthMap::const_iterator monthIt = yearIt->second.begin(); monthIt != yearIt->second.end(); ++monthIt) {
                    int month = monthIt->first;
                    std::cout << "  " << month << std::endl;

                    for (DayMap::const_iterator dayIt = monthIt->second.begin(); dayIt != monthIt->second.end(); ++dayIt) {
                        int day = dayIt->first;
                        double value = dayIt->second;
                        std::cout << "    " << day << ": " << value << std::endl;
                    }
                }
            }
        }
        double getBitcoinExchangeRate(int year, int month, int day);
        double  findDataCloseTo(int year, int month, int day);
        void    addData(int year, int month, int day, double value) {
            if( ! validateYear(year) || ! validateMonth(month) || ! validateDay(day)) {
                std::stringstream ss;
                ss << "Error: year, month or day out of range." << year << "-" << month << "-" << day;
                throw std::runtime_error(ss.str());
            }
            data_[year][month][day] = value;
        }
        void dumpDatabaseData(int year, int month, int day) {
            BitCoinMap::iterator yearIt = data_.find(year);
            if (yearIt != data_.end()) {
                MonthMap::iterator monthIt = yearIt->second.find(month);
                if (monthIt != yearIt->second.end()) {
                    DayMap::iterator dayIt = monthIt->second.find(day);
                    if (dayIt != monthIt->second.end()) {
                        std::cout << dayIt->second << std::endl;
                        return;
                    }
                }
            }
            std::cerr << "Error: Data not found for the given date." << std::endl;
        }
};



#endif
