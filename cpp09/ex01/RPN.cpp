#include "RPN.hpp"
#include <sstream>
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

void RPN::add_operation(void){
    std::cout << "add" << std::endl;
    if (this->mintos.size() <= 1)
        {
            std::cout << "error" << std::endl;
            return;
        }
    double first = mintos.top();
    mintos.pop();
    double second = mintos.top();
    mintos.pop();
    mintos.push(second + first);
    return;
}

void RPN::sub_operation(void){
    std::cout << "sub" << std::endl;
        std::cout << "add" << std::endl;
    if (this->mintos.size() <= 1)
        {
            std::cout << "error" << std::endl;
            return;
        }
    double first = mintos.top();
    mintos.pop();
    double second = mintos.top();
    mintos.pop();
    mintos.push(second + first);
    return;
}

void RPN::mul_operation(void){
    std::cout << "mul" << std::endl;
        std::cout << "add" << std::endl;
    if (this->mintos.size() <= 1)
        {
            std::cout << "error" << std::endl;
            return;
        }
    double first = mintos.top();
    mintos.pop();
    double second = mintos.top();
    mintos.pop();
    mintos.push(second + first);
    return;
}

void RPN::div_operation(void){
    std::cout << "div" << std::endl;
        std::cout << "add" << std::endl;
    if (this->mintos.size() <= 1)
        {
            std::cout << "error" << std::endl;
            return;
        }
    double first = mintos.top();
    mintos.pop();
    double second = mintos.top();
    mintos.pop();
    mintos.push(second + first);
    return;
}

bool NameChecker(std::string const &name){
    if (name == "+" || name == "-" || name == "*" || name == "/")
        return true;
    if (name.find_first_not_of("0123456789") == std::string::npos)
        return true;
    return false;
}

double RPN::RpnCaller(std::stringstream &name){
    std::string temp;
    name >> temp ;
    while(temp != "")
    {
        std::cout << temp << std::endl;
        if(NameChecker(temp) == true){
            if (temp == "+")
                this->add_operation();
            else if (temp == "-")
                this->sub_operation();
            else if (temp == "*")
                this->mul_operation();
            else if (temp == "/")
                this->div_operation();
            else
            {
                std::cout << "debug pushing " << std::endl;
                double test = std::stod(temp);
                this->mintos.push(test);
            }
        }
        else
        {
            std::cout << "Error" << std::endl;
            return -1;
        }
        name >> temp;
    }
    return this->mintos.top();
}