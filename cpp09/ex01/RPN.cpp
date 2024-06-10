/**********************************************************
 // -> : ██████╗ █████╗ ███████╗███████╗ █████╗ ██████╗
        ██╔════╝██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗
        ██║     ███████║█████╗  ███████╗███████║██████╔╝
        ██║     ██╔══██║██╔══╝  ╚════██║██╔══██║██╔══██╗
        ╚██████╗██║  ██║███████╗███████║██║  ██║██║  ██║
         ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝
 // -> Author:        mabahani
 // -> Modified by:   CZAR
 // -> Modified time: 2024-06-05 19:21:20
 **********************************************************/

#include "RPN.hpp"

RPN::RPN(){
}

RPN::~RPN(){
}

RPN::RPN(const RPN& other){
    this->mintos = other.mintos;
}

RPN& RPN::operator=(const RPN& other){
    this->mintos = other.mintos;
    return *this;
}

double RPN::strToDouble(std::string test){
    std::stringstream ss;
    double var;
    ss << test;
    ss >> var;
    return var;
}

bool RPN::NameChecker(std::string const &name){
    if (name.find_first_not_of("0123456789") == std::string::npos)
        return true;
    std::cout <<">>|"<< name << "|<<" << std::endl;
    return false;
}


double RPN::rpn(std::stringstream & tokens) {
    std::string token;
    while (tokens >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (mintos.size() < 2) {
                throw std::runtime_error("Error :no left numbers to perform on");
            }
            int b = mintos.top();
            mintos.pop();
            int a = mintos.top();
            mintos.pop();

            if (token == "+")
                mintos.push(a + b);
            if (token == "-")
                mintos.push(a - b);
            if (token == "*")
                mintos.push(a * b);
            if (token == "/")
                mintos.push(a / b);

        } else {
            if (NameChecker(token) && strToDouble(token) < 10)
                    mintos.push(strToDouble(token));
            else
                throw std::runtime_error("Error : bad input");
        }
    }
    if(mintos.size() != 1)
        throw std::runtime_error("Error");
    return mintos.top();
}
