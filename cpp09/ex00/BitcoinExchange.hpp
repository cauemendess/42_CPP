#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <sstream>


class BitcoinExchange
{
private: 
    std::map<std::string, double> _exchangeRates;

public:
    BitcoinExchange (char **argv);
    BitcoinExchange (const BitcoinExchange &other);
    BitcoinExchange &operator= (const BitcoinExchange &other);
    ~BitcoinExchange ();

    void loadDatabase (std::string filename);
    void validateDatabaseLine (std::string line, size_t lineNumber);
    bool isDateValid (std::string date);
    bool isValueValid (std::string date);
    bool haveAplha (std::string str);

    void throwError(size_t lineNumber, const std::string &message);
    std::map<std::string, double>::iterator getNearestDate (std::string inputDate);
    bool validadeInputLine (std::string line);
    void printData (std::ifstream &file, std::ostream &out);
    void trim (std::string &str);

};


#endif