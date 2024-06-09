/**********************************************************
 // -> : ██████╗ █████╗ ███████╗███████╗ █████╗ ██████╗ 
        ██╔════╝██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗ 
        ██║     ███████║█████╗  ███████╗███████║██████╔╝ 
        ██║     ██╔══██║██╔══╝  ╚════██║██╔══██║██╔══██╗ 
        ╚██████╗██║  ██║███████╗███████║██║  ██║██║  ██║ 
         ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝
 // -> Author:        mabahani
 // -> Modified by:   CZAR
 // -> Modified time: 2024-06-05 19:21:24
 **********************************************************/

#include "RPN.hpp"

// still has another method
//to do:
// add negative numbers

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
        ss << " " << av[i];
    double res = rpn.RpnCaller(ss);
    double res1 = rpn.rpn(ss);
    if(res != -1)
        std::cout << res << std::endl;
    if(res1 != -1)
        std::cout << res1 << std::endl;
    return 0;
}