#include "RPN.hpp"


int main(int ac, char **av)
{
    RPN rpn;
    std::string str;
    std::stringstream ss;
    if (ac == 1)
    {
        std::cout << "No arguments" << std::endl;
        return 0;
    }
    for (int i = 1; i < ac; i++)
    {
        ss << " " << av[i];
        std::cout << av[i] << std::endl;
    }
    exit(0);
    double res = rpn.RpnCaller(ss);
    if(res != -1)
        std::cout << res << std::endl;
    return 0;
}