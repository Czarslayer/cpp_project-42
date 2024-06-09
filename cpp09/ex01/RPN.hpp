/**********************************************************
 // -> : ██████╗ █████╗ ███████╗███████╗ █████╗ ██████╗ 
        ██╔════╝██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗ 
        ██║     ███████║█████╗  ███████╗███████║██████╔╝ 
        ██║     ██╔══██║██╔══╝  ╚════██║██╔══██║██╔══██╗ 
        ╚██████╗██║  ██║███████╗███████║██║  ██║██║  ██║ 
         ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝
 // -> Author:        mabahani
 // -> Modified by:   CZAR
 // -> Modified time: 2024-06-05 19:21:18
 **********************************************************/

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;


class RPN {
    private:
        stack<double> mintos;
    public:
        RPN();
        ~RPN();
        RPN & operator=(RPN const & other);
        RPN(const RPN & other);
        double  rpn(std::stringstream & tokens);
        bool add_operation(void);
        bool sub_operation(void);
        bool mul_operation(void);
        bool div_operation(void);
        double RpnCaller(std::stringstream& name);
};
#endif
