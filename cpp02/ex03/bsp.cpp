#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = Point::abs((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())));
    Fixed areaABP = Point::abs((a.getX() * (b.getY() - point.getY()) + b.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - b.getY())));
    Fixed areaACP = Point::abs((a.getX() * (point.getY() - c.getY()) + point.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - point.getY())));
    Fixed areaBCP = Point::abs((b.getX() * (point.getY() - c.getY()) + point.getX() * (c.getY() - b.getY()) + c.getX() * (b.getY() - point.getY())));
    if(areaBCP == 0 || areaABP == 0 || areaACP == 0)
        return  false;
    if ( areaABC == areaABP + areaACP + areaBCP)
        return true;
    return false;
}