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
void getValueAndDate(std::string line,std::string& date, std::string& rate,std::string delimiter);
bool isValidDate(int year, int month, int day);

struct FileGuard {
private:
    std::ifstream file;
    FileGuard(){};

public:
    FileGuard(const std::string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileGuard() {
        if (file.is_open()) {
            file.close();
        }
    }

    std::ifstream& getStream() {
        return file;
    }
};


class BitcoinExchange
{
    typedef std::map<int, double> DayMap;
    typedef std::map<int, DayMap> MonthMap;
    typedef std::map<int, MonthMap> BitCoinMap;
    
    private:
        BitCoinMap data_;
    
    public:
        BitcoinExchange();
        BitcoinExchange(std::string file);
        BitcoinExchange(BitCoinMap data);
        BitcoinExchange(const BitcoinExchange &r);
        ~BitcoinExchange();
        BitcoinExchange & operator= (const BitcoinExchange &other);
        void        initDatabase(std::string file);
        void        insertData(int year, int month, int day, double value);
        void        insertFromString(const std::string& input);
        double      getBitcoinExchangeRate(int year, int month, int day);
        double      findDataCloseTo(int year, int month, int day);
        void        addData(int year, int month, int day, double value);
        void        findOrFail(int year, int month, int day);
        void        printDatabase();

        class FindOrFailException : public std::exception {
            std::string message_;
            std::string fullMessage_;

            public:
                explicit FindOrFailException(const char *message)
                    : message_(message), fullMessage_("Trying to get property " + message_ + " of non-object.") {}

                virtual ~FindOrFailException() throw() {}

                virtual const char* what() const throw() {
                    return fullMessage_.c_str();
                }
        };
};

#endif
