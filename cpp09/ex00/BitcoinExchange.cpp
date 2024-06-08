/**********************************************************
 // -> : ██████╗ █████╗ ███████╗███████╗ █████╗ ██████╗ 
        ██╔════╝██╔══██╗██╔════╝██╔════╝██╔══██╗██╔══██╗ 
        ██║     ███████║█████╗  ███████╗███████║██████╔╝ 
        ██║     ██╔══██║██╔══╝  ╚════██║██╔══██║██╔══██╗ 
        ╚██████╗██║  ██║███████╗███████║██║  ██║██║  ██║ 
         ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝
 // -> Author:        mabahani
 // -> Modified by:   CZAR
 // -> Modified time: 2024-06-05 19:21:39
 **********************************************************/

#include "BitcoinExchange.hpp"
#include <fstream>

#include <ctime>

BitcoinExchange::BitcoinExchange()
{
    std::fstream file;
    file.open("data.csv", std::ios::out | std::ios::in);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::string name = line.substr(0, line.find(','));
            if (name == "date")
                continue;
            double price = StrToDouble(line.substr(line.find(',') + 1).c_str());
            _original[name] = price;
        }
        file.close();
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    if (this == &other)
    {
        return;
    }
    BitcoinExchange();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
    {
        return *this;
    }
    BitcoinExchange();
    return *this;
}

int BitcoinExchange::checkbadsyntax(std::string &line)
{
    if (line.find('|') == std::string::npos)
    {
        return 0;
    }
    //------------------------------------------------
    if(line == "date | value")
        return 0;
    return 1;
}

bool BitcoinExchange::checktimeformat(std::string &name)
{
    name = name.erase(0,name.find_first_not_of(" \t"));
    name = name.erase(name.find_last_not_of(" \t") + 1);
    if (name.size() != 10)
    {
        return false;
    }
    for (size_t i = 0; i < name.size(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (name[i] != '-')
            {
                return false;
            }
        }
        else
        {
            if (name[i] < '0' || name[i] > '9')
            {
                return false;
            }
        }
    }
    std::string year = name.substr(0, 4);
    std::string month = name.substr(5, 2);
    std::string day = name.substr(8, 2);
    if (std::atoi(year.c_str()) < 2009)
    {
        return false;
    }
    if (std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
    {
        return false;
    }
    if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31)
    {
        return false;
    }
//    std::cout << GTOT() << std::endl;
    if(name.compare(GTOT()) > 0) {
        std::cout << "your date is in the future: ";
        return false;
    }
    if(name.compare("2009-01-02") < 0) {
        std::cout << "No data for the input date: ";
        return false;
    }
    return true;
}

bool BitcoinExchange::checkprice(const std::string &price) const
{
    std::string temp;
    if(price[0] == ' ')
         temp = price.substr(price.find_first_not_of(" \t"));
    else
         temp = price;
    if (temp.find_first_not_of("0123456789.") != std::string::npos)
    {
        // check if the number is negative
        if (temp[0] == '-' && (temp).find_first_not_of("0123456789.",1) == std::string::npos
            && temp.find('.') == temp.find_last_of('.'))
        {
            std::cout << "Error : not a positive number"<< std::endl;
            return false;
        }
        // check if he gived a positive
        if (temp[0] == '+' && (temp).find_first_not_of("0123456789.",1) == std::string::npos
            && temp.find('.') == temp.find_last_of('.'))
        {
            temp = temp.substr(1);

        } else {
            std::cout << "Error : bad input => " << temp << std::endl;
            return false;
        }
    }
    if (temp.find('.') != std::string::npos)
    {
        if (temp.find('.') != temp.find_last_of('.'))
        {
            std::cout << "Error : bad input => " << temp << std::endl;
            return false;
        }
    }
    else
    {
        if (atol(temp.c_str()) > 1000)
        {
            std::cout << "Error : too large a number" << std::endl;
            return false;
        }
    }
    return true;
}

void BitcoinExchange::parseOffers(const std::string &filename)
{
    std::fstream file;
    file.open(filename.c_str(), std::ios::out | std::ios::in);
    if (file.is_open())
    {
        std::string line;
        std::string name;
        double price;
        while (std::getline(file, line)) {
            if (checkbadsyntax(line) == 1) {
                std::string date = line.substr(0, line.find('|'));
                if (checktimeformat(date) == false) {
                    std::cout << "Bad time => "<< date << std::endl;
                    continue;
                }
                name = date;
                if (checkprice(line.substr(line.find('|') + 1)) == true) {
                    price = StrToDouble(line.substr(line.find('|') + 1).c_str());
                }
                else
                    continue;
            } else {
                if (line.empty() != true && line.compare("date | value") != 0)
                    std::cout << "Error : bad input => " << line << std::endl;
                continue;
            }
            printoffers(name, price);
        }
        file.close();
    }
    else
    {
        std::cout << "File not found" << std::endl;
    }
}

void BitcoinExchange::printoffers(std::string time, double price) {
    std::map<std::string,double>:: iterator it;
    it = _original.lower_bound(time);
    if(it->first != time)
        it--;
    double Bprice = it->second;
    std::cout << time << " => " << price << " = " << price * Bprice << std::endl;
}

double BitcoinExchange::StrToDouble(std::string TheString) {
    std::stringstream ss;
    double var;
    ss << TheString;
    ss >> var;
    return var;
}

void itos(int theNumber, std::string &date)
{
    std::stringstream ss;
    ss << theNumber;
    ss >> date;
}

std::string const BitcoinExchange::GTOT() {
    time_t now = time(0);
    tm  *ltm = localtime(&now);
    std::string y, m, d;
    itos(1900 + ltm->tm_year, y);
    itos(1 + ltm->tm_mon , m);
    itos(ltm->tm_mday, d);
    const std::string all(y + "-" + (m.length()==1 ? "0"+m : m) + "-" + (d.length() == 1 ? "0"+d : d));
    return (all);
}