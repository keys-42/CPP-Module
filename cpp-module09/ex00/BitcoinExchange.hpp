#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <map>
# include <exception>
# include <climits>
# include <iomanip>
# include <cmath>
# include <limits>

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
# define BTCSTSRTYEAROFUSE 2009
# define BTCSTSRTMONTHOFUSE 1
# define BTCSTSRTDAYOFUSE 2

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
    private:
        std::map<std::string, double> data_;
    
    public:
        BitcoinExchange();
        BitcoinExchange(std::string file);
        BitcoinExchange(std::map<std::string, double> data);
        BitcoinExchange(const BitcoinExchange &r);
        ~BitcoinExchange();
        BitcoinExchange & operator= (const BitcoinExchange &other);
        void                initDatabase(std::string file);
        void                insertFromString(const std::string& input);
        double              getBitcoinExchangeRate(std::string s);
        void                printDatabase();
        static bool         isValidDate(std::string s);
        static bool         validDate(int year, int month, int day);
};

#endif
