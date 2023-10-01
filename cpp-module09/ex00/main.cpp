#include "BitcoinExchange.hpp"

bool
makeBitcoinExchange(BitcoinExchange& btc) {

	try {
		btc.initDatabase(DATABASE);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return false;
	}
	return true;
}

void
output(std::string s, double value, double newValue) {
	std::cout << s << " => " << value << " = " << newValue << std::endl;
}

void
tryExchange(std::string line, BitcoinExchange& btc) {

	std::string::size_type pos = line.find(" | ");

	if (pos == std::string::npos) {
		throw std::invalid_argument("Error: bad input => " + line);
	}
	std::string datePart = line.substr(0, pos);
	std::string valuePart = line.substr(pos + 3);
	std::istringstream ss(valuePart);
	double value;
	ss >> value;
	if (ss.fail() || !ss.eof()) {
		throw std::logic_error("Error: invalid number format or out of range => " +
							   line);
	}
	if (value > 1000.0) {
		throw std::out_of_range("Error: too large a number.");
	}
	if (value < 0.0) {
		throw std::out_of_range("Error: not a positive number.");
	}
	if (!BitcoinExchange::isValidDate(datePart)) {
		throw std::out_of_range("Error: year, month or day out of range." +
								datePart);
	}
	double rate = btc.getBitcoinExchangeRate(datePart);
	double newValue = rate * static_cast<double>(value);
	output(datePart, value, newValue);
}

bool
convert(char* file, BitcoinExchange& btc) {
	try {
		FileGuard f(file);
		std::string line;
		getline(f.getStream(), line);
		if (line.compare(INPUTFORMAT) != 0)
			throw std::logic_error("Error: Input file format");
		while (getline(f.getStream(), line)) {
			try {
				tryExchange(line, btc);
			} catch (std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return false;
	}
	return true;
}

int
main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " file" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	if (!makeBitcoinExchange(btc)) {
		return 1;
	}
	if (!convert(argv[1], btc)) {
		return 1;
	}
	// btc.printDatabase();
	return 0;
}
