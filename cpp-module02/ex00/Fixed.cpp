#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	v = 0;
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


int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return v;
}

void Fixed::setRawBits(int const raw)
{
	v = raw;
}
