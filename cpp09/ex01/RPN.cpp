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
    return false;
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
                double test = std::stod(temp);
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