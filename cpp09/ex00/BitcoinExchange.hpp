/**********************************************************
 // -> : ██████╗ █████╗ ███████╗███████╗ █████╗ ██████╗ 
        ██╔════╝██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗ 
        ██║     ███████║█████╗  ███████╗███████║██████╔╝ 
        ██║     ██╔══██║██╔══╝  ╚════██║██╔══██║██╔══██╗ 
        ╚██████╗██║  ██║███████╗███████║██║  ██║██║  ██║ 
         ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝
 // -> Author:        mabahani
 // -> Modified by:   CZAR
 // -> Modified time: 2024-06-05 19:21:33
 **********************************************************/

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stdlib.h>
#include <sstream>
class BitcoinExchange
{
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    void parseOffers(const std::string &filename);
    int checkbadsyntax(std::string &line);
    bool checktimeformat( std::string &name);
    bool checkprice(const std::string &price) const;
    void printoffers(std::string time, double price);
    std::string const GTOT();
    double StrToDouble(std::string TheString) const;

private:
    // std::map<std::string, double> _offers;
    std::map<std::string, double> _original;
};

#endif