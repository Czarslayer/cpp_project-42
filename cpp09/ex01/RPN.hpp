#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;


class RPN {
    private:
        stack<double> mintos;
    public:
        RPN();
        ~RPN();
        RPN & operator=(RPN const & other);
        RPN(const RPN & other);
        void add_operation(void);
        void sub_operation(void);
        void mul_operation(void);
        void div_operation(void);
        double RpnCaller(std::stringstream& name);
};
#endif
