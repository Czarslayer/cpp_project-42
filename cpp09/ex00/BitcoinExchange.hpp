#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

class BitcoinExchange {
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void parseOffers(const std::string& filename);
        int checkbadsyntax(std::string& line);
        bool checktimeformat(const std::string& name) const;
        bool checkprice(const std::string& price) const;

    private:
        std::map<std::string, double> _offers;
        std::map<std::string, double> _original;
};


#endif