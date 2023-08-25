#include "Fixed.hpp"

int main ( void ){
    Fixed a(1.01f);
    Fixed b(1.001f);
    Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    
    std::cout << std::endl;

    std::cout << ( a > b ) << std::endl;
    std::cout << ( a < b ) << std::endl;
    std::cout << ( a >= b ) << std::endl;
    std::cout << ( a <= b ) << std::endl;
    std::cout << ( a == b ) << std::endl;
    std::cout << ( a != b ) << std::endl;

    std::cout << std::endl;

    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;

    std::cout << std::endl;

    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << std::endl;

    std::cout << --b << std::endl;
    std::cout << b << std::endl;
    std::cout << b-- << std::endl;
    std::cout << b << std::endl;

    std::cout << std::endl;

    std::cout << c << std::endl;
    
    std::cout << std::endl;

    std::cout << Fixed::min( a, b ) << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    
    std::cout << std::endl;
    const Fixed d(100.01234f);
    const Fixed e(-100.01234f);
    std::cout << Fixed::min( d, e ) << std::endl;
    std::cout << Fixed::max( d, e ) << std::endl;
    return 0;
}