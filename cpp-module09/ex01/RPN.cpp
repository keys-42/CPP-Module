#include "RPN.hpp"

Rpn::Rpn() {
	calcPtr[0] = &Rpn::sumNumber;
	calcPtr[1] = &Rpn::differenceNumber;
	calcPtr[2] = &Rpn::productNumber;
	calcPtr[3] = &Rpn::quotientNumber;
};

Rpn::Rpn(const Rpn& r)
	: stack_(r.stack_) {
	calcPtr[0] = &Rpn::sumNumber;
	calcPtr[1] = &Rpn::differenceNumber;
	calcPtr[2] = &Rpn::productNumber;
	calcPtr[3] = &Rpn::quotientNumber;
};

Rpn::~Rpn(){};

Rpn& Rpn::operator=(const Rpn& other) {
	if (this != &other) {
		this->stack_ = other.stack_;
		for (int i = 0; i < 4; ++i) {
			this->calcPtr[i] = other.calcPtr[i];
		}
	}
	return *this;
}

int Rpn::sumNumber(int x, int y) {
	return y + x;
}
int Rpn::differenceNumber(int x, int y) {
	return y - x;
}
int Rpn::productNumber(int x, int y) {
	return y * x;
}
int Rpn::quotientNumber(int x, int y) {
	if (y == 0) throw std::logic_error("Division by zero is not allowed");
	return y / x;
}

int Rpn::stackTop() const {
	return this->stack_.top();
}
void Rpn::stackPop() {
	this->stack_.pop();
}
void Rpn::stackPush(int n) {
	this->stack_.push(n);
}
bool Rpn::isStackEmpty() const {
	if (this->stack_.empty())
		return true;
	return false;
}

void Rpn::calc(char c) {
	const char arr[4] = { '+', '-', '*', '/' };
	int x;
	int y;

	for (int i = 0; i < 4; ++i) {
		if (arr[i] == c) {
			if (this->isStackEmpty())
				throw std::logic_error("logic error: The provided expression is not in RPN.");
			x = this->stackTop();
			this->stackPop();
			if (this->isStackEmpty())
				throw std::logic_error("logic error: The provided expression is not in RPN.");
			y = this->stackTop();
			this->stackPop();
			this->stackPush((this->calcPtr[i])(x, y));
		}
	}
}

void checkInput(const std::string& line) {
	const std::string s = "+-*/";

	for (std::size_t i = 0; i < line.size(); ++i) {
		if ((i % 2) == 0) {
			if ((isdigit(line[i]) == true) || (s.find(line[i]) != std::string::npos)) {
				continue;
			} else {
				throw std::invalid_argument(
					"Invalid argument: The provided expression is not in RPN.");
			}
		} else {
			if (isspace(line[i]) == true) {
				continue;
			} else {
				throw std::invalid_argument(
					"Invalid argument: The provided expression is not in RPN.");
			}
		}
	}
	if (isspace(line[line.size() - 1]) == true)
		throw std::invalid_argument("Invalid argument: The provided expression is not in RPN.");
}

void Rpn::rpn(const std::string& line) {
	try {
		if (line.empty())
			throw std::invalid_argument("Error: The provided RPN expression is empty.");
		checkInput(line);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return;
	}

	try {
		for (std::size_t i = 0; i < line.size(); ++i) {
			if (isdigit(line[i]) == true) {
				this->stackPush(line[i] - '0');
			} else if (isspace(line[i])) {
				continue;
			} else {
				this->calc(line[i]);
			}
		}
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return;
	}

	try {
		int result = this->stackTop();
		this->stackPop();
		if (!this->isStackEmpty()) {
			throw std::runtime_error("Invalid input: The provided expression is not in RPN.");
		}
		std::cout << result << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
