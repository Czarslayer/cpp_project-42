#include "iter.hpp"

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    iter(intArray, 5, print);
    iter(charArray, 5, print);
    iter(floatArray, 5, print);
    return 0;
}