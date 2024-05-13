#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    try {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (...) {
        std::cout << "Not found" << std::endl;
    }
    

    try {
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "Found: " << *it << std::endl;
    } catch (...) {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}