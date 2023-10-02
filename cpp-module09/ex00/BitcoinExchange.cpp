#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& file) {
	initDatabase(file);
}

BitcoinExchange::BitcoinExchange(const std::map<std::string, double>& data)
	: data_(data){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& r)
	: data_(r.data_){};

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		this->data_ = other.data_;
	return *this;
}

void BitcoinExchange::initDatabase(const std::string& file) {
	FileGuard f(file.c_str());
	std::string line;
	getline(f.getStream(), line);
	if (line.compare(DATABASEFORMAT))
		throw std::logic_error("Error: database format");
	while (getline(f.getStream(), line)) {
		insertFromString(line);
	}
}

void BitcoinExchange::insertFromString(const std::string& input) {
	std::istringstream ss(input);
	std::string s;
	double value;
	std::getline(ss, s, ',');
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		throw std::logic_error("Error: database format");
	}
	if (!BitcoinExchange::isValidDate(s)) {
		throw std::out_of_range("Error: year, month or day out of range." + s);
	}
	data_[s] = value;
}

double BitcoinExchange::getBitcoinExchangeRate(std::string s) {
	std::map<std::string, double>::iterator it = data_.lower_bound(s);

	if (s.compare(it->first)) {
		--it;
	}
	return it->second;
}

bool BitcoinExchange::isValidDate(std::string s) {
	std::istringstream ss(s);
	int year, month, day;
	char dash, dash2;

	ss >> year >> dash >> month >> dash2 >> day;

	if (ss.fail()) {
		throw std::logic_error("Error: invalid number format or out of range => " + s);
	}
	if (dash != '-' || dash2 != '-' || !ss.eof()) {
		throw std::invalid_argument("Error: bad input => " + s);
	}
	if (!BitcoinExchange::validDate(year, month, day)) {
		return false;
	}
	return true;
}

bool BitcoinExchange::validDate(int year, int month, int day) {
	if (year == BTCSTSRTYEAROFUSE && month == BTCSTSRTMONTHOFUSE && day < BTCSTSRTDAYOFUSE)
		return false;
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
	if (month == 2) {
		return (isLeap && day <= 29) || (!isLeap && day <= 28);
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return day <= 30;
	} else {
		return day <= MAXDAY;
	}
}
