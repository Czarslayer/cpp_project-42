#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion(std::string input) : _input(input) {
}

ScalarConversion::~ScalarConversion() {
}

void ScalarConversion::convertChar() {
    std::cout << "char: ";
    try {
        char c = static_cast<char>(atoi(this->_input.c_str()));
        
        if (c < 32 || c > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << c << "'" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

void ScalarConversion::convertInt() {
    std::cout << "int: ";
    try {
        int i = atoi(this->_input.c_str());
        std::cout << i << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

void ScalarConversion::convertFloat() {
	std::cout << "float: ";
	try {
		float f = atof(this->_input.c_str());
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConversion::convertDouble() {
    std::cout << "double: ";
	try {
		double d = atof(this->_input.c_str());
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConversion::convert() {
    this->convertChar();
    this->convertInt();
    this->convertFloat();
    this->convertDouble();
}


