#include "Fixed.hpp"

Fixed::Fixed()
	: value_(0) {}

Fixed::Fixed(const int value) {
	value_ = value << bit_;
}

Fixed::Fixed(const float value) {
	value_ = roundf(value * (1 << bit_));
}

Fixed::Fixed(const Fixed& f) {
	*this = f;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& r) {
	this->setRawBits(r.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

int Fixed::getRawBits(void) const {
	return value_;
}

void Fixed::setRawBits(int const raw) {
	value_ = raw;
}

float Fixed::toFloat(void) const {
	return (float)value_ / (float)(1 << bit_);
}

int Fixed::toInt(void) const {
	return (int)roundf((float)value_ / (float)(1 << bit_));
}

bool Fixed::operator>(const Fixed& r) const {
	return this->getRawBits() > r.getRawBits();
}

bool Fixed::operator<(const Fixed& r) const {
	return this->getRawBits() < r.getRawBits();
}

bool Fixed::operator>=(const Fixed& r) const {
	return this->getRawBits() >= r.getRawBits();
}

bool Fixed::operator<=(const Fixed& r) const {
	return this->getRawBits() <= r.getRawBits();
}

bool Fixed::operator==(const Fixed& r) const {
	return this->getRawBits() == r.getRawBits();
}

bool Fixed::operator!=(const Fixed& r) const {
	return this->getRawBits() != r.getRawBits();
}

Fixed Fixed::operator+(const Fixed& r) const {
	return Fixed(this->toFloat() + r.toFloat());
}

Fixed Fixed::operator-(const Fixed& r) const {
	return Fixed(this->toFloat() - r.toFloat());
}

Fixed Fixed::operator*(const Fixed& r) const {
	return Fixed(this->toFloat() * r.toFloat());
}

Fixed Fixed::operator/(const Fixed& r) const {
	return Fixed(this->toFloat() / r.toFloat());
}

Fixed& Fixed::operator++(void) {
	++this->value_;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++this->value_;
	return tmp;
}

Fixed& Fixed::operator--(void) {
	--this->value_;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	--this->value_;
	return tmp;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
	bool f = f1 < f2;
	if (f) {
		return f1;
	}

	return f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
	bool f = f1 < f2;
	if (f) {
		return f1;
	}

	return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
	bool f = f1 < f2;
	if (f) {
		return f2;
	}

	return f1;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
	bool f = f1 < f2;
	if (f) {
		return f2;
	}

	return f1;
}
