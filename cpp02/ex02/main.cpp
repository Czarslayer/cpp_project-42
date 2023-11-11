#include "Fixed.hpp"

int main(void) {
    Fixed a( 5.05f);
    Fixed const b( Fixed( 5.05f ) / Fixed( 2.0f ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;
    if( a > b )
        std::cout << "a is greater than b" << std::endl;
    if( a < b )
        std::cout << "a is less than b" << std::endl;
    if( a >= b )
        std::cout << "a is greater or equal to b" << std::endl;
    if( a <= b )
        std::cout << "a is less or equal to b" << std::endl;
    if( a == b )
        std::cout << "a is equal to b" << std::endl;
    if( a != b )
        std::cout << "a is not equal to b" << std::endl;
    return 0;
}