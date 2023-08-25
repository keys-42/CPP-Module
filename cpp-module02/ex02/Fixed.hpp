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
		Fixed(const Fixed & f);
		~Fixed();
		Fixed & operator=( const Fixed & r);
		
		int getRawBits( void ) const;
		void setRawBits(int const raw);

		float toFloat( void ) const;
		int toInt( void ) const;

		//https://runebook.dev/ja/docs/cpp/language/operator_assignment
		bool operator>(const Fixed & r) const;
		bool operator<(const Fixed & r) const;
		bool operator>=(const Fixed & r) const;
		bool operator<=(const Fixed & r) const;
		bool operator==(const Fixed & r) const;
		bool operator!=(const Fixed & r) const;

		Fixed operator+(const Fixed & r) const;
		Fixed operator-(const Fixed & r) const;
		Fixed operator*(const Fixed & r) const;
		Fixed operator/(const Fixed & r) const;

		Fixed & operator++( void );
		Fixed operator++( int );
		Fixed & operator--( void );
		Fixed operator--( int );
		
		static Fixed& min( Fixed& f1, Fixed& f2);
		static const Fixed& min( const Fixed& f1, const Fixed& f2);
		static Fixed& max( Fixed& f1, Fixed& f2);
		static const Fixed& max( const Fixed& f1, const Fixed& f2);
};

#endif
