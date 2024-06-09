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

int main(int ac, char **av)
{
    RPN rpn;
    std::stringstream ss;
    try {
        if (ac == 1) {
            std::cout << "Usage: ./RPN \"your numbers\"" << std::endl;
            std::cout << "      > Ps: (*)< will be considered a\n              wildcard without quotes" << std::endl;
            std::cout << "      > no decimals or brakets" << std::endl;
            return 0;
        }
        for (int i = 1; i < ac; i++)
            ss << " " << av[i];
        double res = rpn.rpn(ss);
        std::cout << res << std::endl;
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}