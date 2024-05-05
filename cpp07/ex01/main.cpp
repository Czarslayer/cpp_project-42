#include "iter.hpp"

template <typename T>
void print(T x)
{
    std::cout << x << std::endl;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    iter<int>(intArray, 5, print<int>);
    iter<char>(charArray, 5, print<char>);
    iter<float>(floatArray, 5, print<float>);
    return 0;
}

