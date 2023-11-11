
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

bool Fixed::operator>(const Fixed &fixed) const {
    return _value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
    return _value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return _value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return _value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
    return _value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return _value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    Fixed tmp;
    tmp.setRawBits(_value + fixed.getRawBits());
    return tmp;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    Fixed tmp;
    tmp.setRawBits(_value - fixed.getRawBits());
    return tmp;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    Fixed tmp;
    tmp.setRawBits((_value * fixed.getRawBits()) / ( 1 << _bits));
    return tmp;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    Fixed tmp;
    tmp.setRawBits((_value * (1 << _bits)) / fixed.getRawBits());
    return tmp;
}

Fixed &Fixed::operator++() {
    _value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    _value++;
    return tmp;
}

Fixed &Fixed::operator--() {
    _value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    _value--;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return a > b ? a : b;
}

