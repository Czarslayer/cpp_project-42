#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange() {
    std::fstream file;
    file.open("offers.csv", std::ios::out | std::ios::in);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string name = line.substr(0, line.find(','));
            double price = std::stod(line.substr(line.find(',') + 1));
            _original[name] = price;
        }
        file.close();
    }
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _offers = other._offers;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _offers = other._offers;
    }
    return *this;
}

int BitcoinExchange::checkbadsyntax(std::string& line) {
    if (line.find('|') == std::string::npos) {
        return 0;
    }
    // check the time format
    return 1;
}

bool BitcoinExchange::checktimeformat(const std::string& name) const {
    // first we split the string to three parts year, month, day by -
    // then we check if the year is 4 digits, month is 2 digits and day is 2 digits
    // then we check if the year is between 2000 and 2020, month is between 1 and 12 and day is between 1 and 31
    // if any of the checks fail we return 0
    if (name.size() != 10) {
        return false;
    }
    for (int i = 0; i < name.size(); i++) {
        if (i == 4 || i == 7) {
            if (name[i] != '-') {
                return false;
            }
        } else {
            if (name[i] < '0' || name[i] > '9') {
                return false;
            }
        }
    }
    std::string year = name.substr(0, 4);
    std::string month = name.substr(5, 2);
    std::string day = name.substr(8, 2);
    if (std::stoi(year) < 2000 || std::stoi(year) > 2020) {
        return false;
    }
    if (std::stoi(month) < 1 || std::stoi(month) > 12) {
        return false;
    }
    if (std::stoi(day) < 1 || std::stoi(day) > 31) {
        return false;
    }
    return true;
}

bool BitcoinExchange::checkprice(const std::string& price) const {
    // check if the price is a number using find first not of
    
    if (price.find_first_not_of("0123456789.") != std::string::npos) {
        return false;
    }
    if(price.find('.') != std::string::npos) {
        if (price.find('.') != price.find_last_of('.')) {
            return false;
        }
    } else {
        if (std::stoi(price) < 0 || std::stoi(price) > 1000){
            return false;
        }
    }
    // check if the price is a double
}

void BitcoinExchange::parseOffers(const std::string& filename) {
        std::fstream file;
        file.open(filename, std::ios::out | std::ios::in);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                if(checkbadsyntax(line) == 1) {
                    if(checktimeformat(line.substr(0, line.find('|'))) == false)
                        std::cout << "Bad time format" << std::endl;
                        std::string name = line.substr(0, line.find('|'));
                
                    double price = std::stod(line.substr(line.find('|') + 1));
                    
                    _offers[name] = price;
                }else {
                    std::cout << "Bad syntax" << std::endl;
                }
            }
            file.close();
        } else {
            std::cout << "File not found" << std::endl;
        }
}