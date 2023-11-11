#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) {
    std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
    std::cout << "Float constructor called" << std::endl;
}

Point::~Point() {
    std::cout << "Destructor called" << std::endl;
}

Point &Point::operator=(const Point &point) {
    std::cout << "Assignation operator called" << std::endl;
    (void)point;
    return *this;
}

Fixed Point::getX(void) const {
    return _x;
}

Fixed Point::getY(void) const {
    return _y;
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "Point(" << point.getX() << ", " << point.getY() << ")";
    return out;
}

Fixed Point::abs(const Fixed &fixed) {

    if (fixed < 0)
        return fixed * Fixed(-1);
    return fixed;
}