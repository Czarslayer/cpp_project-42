
#include "Fixed.hpp"

int main(void) {
    Fixed a( 5.05f);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << "test a:" << a << std::endl;
    std::cout << "test ++a:" << ++a << std::endl; // 6
    std::cout << "test a:" << a << std::endl; // 6
    std::cout << "test a++:" << a++ << std::endl; // 6
    std::cout << "test a:" << a << std::endl; // 7
    std::cout << "test b:"<< b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}