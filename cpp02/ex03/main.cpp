#include "Point.hpp"

int main()
{
// simple test if a point giving is inside a triangle
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point p(3, 3);

    std::cout << "Point a: " << a << std::endl;
    std::cout << "Point b: " << b << std::endl;
    std::cout << "Point c: " << c << std::endl;
    std::cout << "Point p: " << p << std::endl;

    std::cout << "Point p is inside the triangle abc: " << std::boolalpha << bsp(a, b, c, p) << std::endl;
    return 0;
}