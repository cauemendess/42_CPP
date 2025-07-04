#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <iomanip>
#include <algorithm>


class BitcoinExchange
{
public: 
    BitcoinExchange();
    ~BitcoinExchange() {};

    void processFile(const std::string &filename);
private:
    std::map<std::string, float> exchangeRates;



};


#endif