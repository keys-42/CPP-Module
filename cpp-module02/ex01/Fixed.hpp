#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value_;
		static const int bit_ = 8;

		friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);

	public:
		Fixed();
        Fixed( const int value );
		Fixed( const float value );
		~Fixed();
		Fixed(const Fixed & f);
		Fixed & operator=( const Fixed & r);
		
		int getRawBits( void ) const;
		void setRawBits(int const raw);

		float toFloat( void ) const;
		int toInt( void ) const;
};

#endif
