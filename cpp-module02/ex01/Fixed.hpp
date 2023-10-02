#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
private:
	int value_;
	static const int bit_ = 8;

public:
	Fixed();
	explicit Fixed(const int value);
	explicit Fixed(const float value);
	~Fixed();
	Fixed(const Fixed& f);
	Fixed& operator=(const Fixed& r);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
