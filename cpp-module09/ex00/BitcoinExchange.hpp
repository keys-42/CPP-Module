#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <climits>
#include <cmath>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>

#define DATABASE "data.csv"
#define DATABASEFORMAT "date,exchange_rate"
#define DATABASEDELIMITER ','
#define INPUTFORMAT "date | value"
#define INPUTDEDELIMITER " | "
#define MINDAY 1
#define MAXDAY 31
#define MINMONTH 1
#define MAXMONTH 12
#define MINYEAR 2009
#define MAXYEAR 2024
#define BTCSTSRTYEAROFUSE 2009
#define BTCSTSRTMONTHOFUSE 1
#define BTCSTSRTDAYOFUSE 2

std::string getDelimiter(const std::string& line,
	const std::string& front,
	const std::string& back);

struct FileGuard {
private:
	std::ifstream file;
	FileGuard(){};

public:
	explicit FileGuard(const std::string& filename) {
		file.open(filename.c_str());
		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file");
		}
	}

	~FileGuard() {
		if (file.is_open()) {
			file.close();
		}
	}

	std::ifstream& getStream() { return file; }
};

class BitcoinExchange {
private:
	std::map<std::string, double> data_;

public:
	BitcoinExchange();
	explicit BitcoinExchange(const std::string& file);
	explicit BitcoinExchange(const std::map<std::string, double>& data);
	BitcoinExchange(const BitcoinExchange& r);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);
	void initDatabase(const std::string& file);
	void insertFromString(const std::string& input);
	double getBitcoinExchangeRate(std::string s);
	static bool isValidDate(std::string s);
	static bool validDate(int year, int month, int day);
};

#endif
