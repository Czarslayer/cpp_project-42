#include "BitcoinExchange.hpp"
#include <fstream>

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
            double price = std::stod(line.substr(line.find(',') + 1));
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
    // check the time format
    return 1;
}

bool BitcoinExchange::checktimeformat(const std::string &name) const
{

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
    if (std::atoi(year.c_str()) < 2000 || std::atoi(year.c_str()) > 2020)
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
    return true;
}

bool BitcoinExchange::checkprice(const std::string &price) const
{
    // check if the price is a number using find first not of
    // std::cout << "Checking |" << price << "|" <<  std::endl;
    if (price.find_first_not_of("0123456789.") != std::string::npos)
    {
        // std::cout << "it's here 1" << std::endl;
        return false;
    }
    if (price.find('.') != std::string::npos)
    {
        if (price.find('.') != price.find_last_of('.'))
        {
        // std::cout << "it's here 2" << std::endl;
            return false;
        }
    }
    else
    {
        if (std::atoi(price.c_str()) < 0 || std::atoi(price.c_str()) > 1000)
        {
        // std::cout << "it's here 3" << std::endl;
            return false;
        }
    }
    return true;
}

void BitcoinExchange::parseOffers(const std::string &filename)
{
    std::fstream file;
    file.open(filename, std::ios::out | std::ios::in);
    if (file.is_open())
    {
        std::string line;
        std::string name;
        double price;
        while (std::getline(file, line))
        {
            if (checkbadsyntax(line) == 1)
            {
                if (checktimeformat(line.substr(0, line.find('|') - 1)) == false)
                {
                    std::cout << "Bad time format" << std::endl;
                    continue;
                }
                name = line.substr(0, line.find('|') - 1);
                //
                if (checkprice(line.substr(line.find('|') + 2)) == true)
                {
                    price = std::stod(line.substr(line.find('|') + 2).c_str());
                }
                else
                {
                    std::cout << "bad price" << std::endl;
                    continue;
                }
            }
            else
            {
                std::cout << "Bad syntax" << std::endl;
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
    if(it == _original.end())
        exit(1);
    double Bprice = _original[time];
    std::cout << Bprice << std::endl;
    std::cout << time << " => " << price << " = " << price * Bprice << std::endl;
}