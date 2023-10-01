#include "Fixed.hpp"

int main(void) {
	Fixed a(1.01f);
	Fixed b(1);
	Fixed const c(Fixed(5.05f) * Fixed(2));
	Fixed l;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << std::endl;
	std::cout << a << " > " << b << " = " << (a > b) << std::endl;
	std::cout << a << " < " << b << " = " << (a < b) << std::endl;
	std::cout << a << " >= " << b << " = " << (a >= b) << std::endl;
	std::cout << a << " <= " << b << " = " << (a <= b) << std::endl;
	std::cout << a << " = " << b << " = " << (a == b) << std::endl;
	std::cout << a << " != " << b << " = " << (a != b) << std::endl;

	std::cout << std::endl;

	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;

	std::cout << std::endl;

	std::cout << "++l and l++" << std::endl;
	std::cout << l << std::endl;
	std::cout << ++l << std::endl;
	std::cout << l << std::endl;
	std::cout << l++ << std::endl;
	std::cout << l << std::endl;

	std::cout << std::endl;

	std::cout << --b << std::endl;
	std::cout << b << std::endl;
	std::cout << b-- << std::endl;
	std::cout << b << std::endl;

	std::cout << std::endl;

	std::cout << "Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );" << std::endl;
	std::cout << c << std::endl;

	std::cout << std::endl;

	std::cout << "a: " << a << " ; b: " << b << ";" << std::endl;
	std::cout << "Fixed::min( a, b )" << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << "Fixed::max( a, b )" << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl;
	const Fixed d(100.01234f);
	const Fixed e(-100.01234f);
	std::cout << "const d: " << d << " ; const e: " << e << ";" << std::endl;
	std::cout << "Fixed::min( d, e )" << std::endl;
	std::cout << Fixed::min(d, e) << std::endl;
	std::cout << "Fixed::min( d, e )" << std::endl;
	std::cout << Fixed::max(d, e) << std::endl;
	return 0;
}