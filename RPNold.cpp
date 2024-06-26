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


bool RPN::add_operation(void){
    if (this->mintos.size() <= 1)
        {
            std::cout << "error" << std::endl;
            return false;
        }
    double first = mintos.top();
    mintos.pop();
    double second = mintos.top();
    mintos.pop();
    mintos.push(second + first);
    return true;
}

bool RPN::sub_operation(void){
    if (this->mintos.size() <= 1)
        {
            std::cout << "error" << std::endl;
            return false;
        }
    double first = mintos.top();
    mintos.pop();
    double second = mintos.top();
    mintos.pop();
    mintos.push(second - first);
    return true;
}

bool RPN::mul_operation(void){
    if (this->mintos.size() <= 1)
        {
            std::cout << "error" << std::endl;
            return false;
        }
    double first = mintos.top();
    mintos.pop();
    double second = mintos.top();
    mintos.pop();
    mintos.push(second * first);
    return true;
}

bool RPN::div_operation(void){
    if (this->mintos.size() <= 1)
        {
            std::cout << "Error" << std::endl;
            return false;
        }
    double first = mintos.top();
    mintos.pop();
    double second = mintos.top();
    mintos.pop();
    mintos.push(second / first);
    return true;
}

bool NameChecker(std::string const &name){
    if (name == "+" || name == "-" || name == "*" || name == "/")
        return true;
    if (name.find_first_not_of("0123456789") == std::string::npos)
        return true;
    if((name[0] == '+' || name[0] == '-') && (name).find_first_not_of("0123456789", 1) == std::string::npos )
        return true;
    std::cout << name << std::endl;
    return false;
}

double strToDouble(std::string test){
    std::stringstream ss;
    double var;
    ss << test;
    ss >> var;
    return var;
}
double RPN::rpn(std::stringstream & tokens) {
    std::string token;
    try {
        while (tokens >> token) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (mintos.size() < 2) {
                    throw std::runtime_error("Error size");
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
                if (token.find_first_not_of("0123456789") == std::string::npos)
                    mintos.push(strToDouble(token));
                else
                    throw std::runtime_error("Error number");
            }
        }
        return mintos.top();
    } catch (...) {
        std::cerr << "Error" << std::endl;
        return -1;
    }
}

double RPN::RpnCaller(std::stringstream &name){
    std::string temp;
    int i;
    char const *c[] = {"+", "-", "*", "/"};
    while(name >> temp)
    {
        if(NameChecker(temp) == true){
            for (i = 0; i < 4; i++)
            {
                if (temp == c[i])
                    break;
            }
            switch (i)
            {
            case 0:
                if(!this->add_operation())
                    return -1;
                break;
            case 1:
                if(!this->sub_operation())
                    return -1;
                break;
            case 2:
                if(!this->mul_operation())
                    return -1;
                break;
            case 3:
                if(!this->div_operation())
                    return -1;
                break;
            default:
                double test = strToDouble(temp);
                this->mintos.push(test);
            }
        }
        else
        {
            std::cout << "Error" << std::endl;
            return -1;
        }
    }
    return this->mintos.top();
}