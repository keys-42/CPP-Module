#include "RPN.hpp"

Rpn::Rpn() {
    calcPtr[0] = &Rpn::sumNumber;
    calcPtr[1] = &Rpn::differenceNumber;
    calcPtr[2] = &Rpn::productNumber;
    calcPtr[3] = &Rpn::quotientNumber;
};

Rpn::Rpn(const Rpn & r) : stack_(r.stack_){
    calcPtr[0] = &Rpn::sumNumber;
    calcPtr[1] = &Rpn::differenceNumber;
    calcPtr[2] = &Rpn::productNumber;
    calcPtr[3] = &Rpn::quotientNumber;
};

Rpn::~Rpn() {};

Rpn & Rpn::operator= (const Rpn &other) {
    if(this != &other) {
        this->stack_ = other.stack_;
    }
    return *this;
}
int Rpn::sumNumber(int x,int y) const { return y + x; }
int Rpn::differenceNumber(int x, int y) const  { return y - x; }
int Rpn::productNumber(int x, int y) const  { return y * x; }
int Rpn::quotientNumber(int x, int y) const  { return y / x; }

int Rpn::stackTop() const { return this->stack_.top(); }
void Rpn::stackPop() { this->stack_.pop(); }
void Rpn::stackPush(int n) { this->stack_.push(n); }

void Rpn::calc(char c) {
    char arr[4] = { '+', '-', '*', '/' };
    int x;
    int y;

    for( int i =0; i < 4; ++i ) {
        if(arr[i] == c) {
            x = this->stackTop();
            this->stackPop();
            y = this->stackTop();
            this->stackPop();
            this->stackPush((this->*calcPtr[i])(x,y));
        }
    }
}

void checkInput( const std::string &line ) {
    std::string s = "+-*/";

    for( std::size_t i = 0; i < line.size(); ++i ) {
        if( (i % 2) == 0 ){
            if( (isdigit( line[i] ) == true) || (s.find(line[i]) != std::string::npos)) {
                continue;
            } else {
                throw std::runtime_error("Invalid char: The provided expression is not in RPN.");
            }
        } else {
            if(isspace(line[i]) == true) {
                continue;
            } else {
                throw std::runtime_error("Invalid char: The provided expression is not in RPN.");
            }
        }
    }
}

void Rpn::rpn(const std::string &line) {
    try {
        checkInput( line );
    } catch ( std::exception &e ) {
        std::cerr << "Exception: " << e.what() << std::endl;   
        return ;
    }

	for(std::size_t i = 0; i < line.size(); ++i) {
		if(isdigit( line[i] ) == true) {
			this->stackPush( line[i] - '0' );
		} else if(isspace(line[i])) {
			continue;
		} else {
            this->calc(line[i]);
		}
	}

    try {
        int result = this->stackTop();
        this->stackPop();
        if(!this->stack_.empty()) {
            throw std::runtime_error("Invalid input: The provided expression is not in RPN.");
        }
        std::cout << result << std::endl;
    } catch ( std::exception &e ) {
        std::cerr << "Exception: " << e.what() << std::endl;   
    }
}


void Rpn::print() {
    while(! this->stack_.empty()) {
        std::cout << this->stackTop() <<std::endl;
        this->stackPop();
    }
}