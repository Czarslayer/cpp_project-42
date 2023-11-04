#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {
public:
    Point();
    Point(const Point &point);
    Point(const float x, const float y);
    ~Point();
    Point &operator=(const Point &point);
    Fixed getX(void) const;
    Fixed getY(void) const;
    // abs()
    static Fixed abs(const Fixed &fixed);
private:
    Fixed _x;
    Fixed _y;
};

std::ostream &operator<<(std::ostream &out, const Point &point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif