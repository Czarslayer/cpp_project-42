#include "easyfind.hpp"

int main()
{
// simple maim to test
    std::vector<int> v;
    std::map<int, std::string> m;
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    try
    {
        std::map<int, std::string>::iterator it = easyfind(m, 3);
        std::cout << "Found: " << it->second << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    try
    {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    try
    {
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}