#ifndef ScalarConversion_HPP
#define ScalarConversion_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>


class ScalarConversion
{
private:
    std::string _input;
    ScalarConversion();
    ScalarConversion(ScalarConversion const &src);
    ScalarConversion &operator=(ScalarConversion const &rhs);

public:
    ScalarConversion(std::string input);
    ~ScalarConversion();
    void convertChar();
    void convertInt();
    void convertFloat();
    void convertDouble();
    void convert();
};

#endif
