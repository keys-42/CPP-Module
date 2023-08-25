#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value_ = 0;
}

/**
 * 仮定:
 * 32ビットの整数を使用。
 * 上位24ビットは整数部分。
 * 下位8ビットは小数部分。
*/
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	value_ = value << bit_;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	value_ = roundf(value * (1 << bit_));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed & f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;			
}


Fixed & Fixed::operator= ( const Fixed & r)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(r.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

int Fixed::getRawBits(void) const 
{
	return value_;
}

void Fixed::setRawBits(int const raw)
{
	value_ = raw;
}

float Fixed::toFloat(void) const
{
	return (float)value_ / (float)(1 << bit_);
}

int Fixed::toInt(void) const
{
	return (int)roundf((float)value_ / (float)(1 << bit_));
}

