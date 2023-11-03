
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _value = value << _bits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * (1 << _bits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Assignation operator called" << std::endl;
    _value = fixed.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

int Fixed::toInt(void) const {
    return _value >> _bits;
}

float Fixed::toFloat(void) const {
    return (float)_value / (1 << _bits);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}