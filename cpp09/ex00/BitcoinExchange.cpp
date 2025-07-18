#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange (const BitcoinExchange &other)
{
    (void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return *this;
}


BitcoinExchange::BitcoinExchange(char **argv) 
{
    std::ifstream file (argv[1]);
    loadDatabase("data.csv");
    printData(file, std::cout);
}

BitcoinExchange::~BitcoinExchange ()
{
}

void BitcoinExchange::loadDatabase(std::string filename)
{
    std::ifstream file(filename.c_str());
    std::string line;
    size_t i, lineNumber = 0;
    if(!file.is_open())
        throw std::runtime_error("unable to open 'data.csv' file");
    while (std::getline(file, line))
    {
        lineNumber++;
        trim(line);
        if(line =="date,exchange_rate")
            continue;
        validateDatabaseLine(line, lineNumber);
        i = line.find(",");
        if (i != std::string::npos)
        {
            std::string key = line.substr (0, i);
            trim (key);
            double value = std::atof(line.substr (i + 1).c_str());
            _exchangeRates[key] = value;
        } 
        
    }
    file.close();
}

bool BitcoinExchange::isDateValid(std::string date)
{

    if (std::count(date.begin(), date.end(), '-') != 2)
        return false;

    std::stringstream ss(date);
    std::string yearStr, monthStr, dayStr;

    if (!std::getline(ss, yearStr, '-') ||
        !std::getline(ss, monthStr, '-') ||
        !std::getline(ss, dayStr))
        return false;

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (year < 0 || year > 2024)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    return true;
}



void BitcoinExchange::validateDatabaseLine(std::string line, size_t lineNumber)
{
    if (line.empty())
        throwError(lineNumber, "empty line");

    size_t commaPos = line.find(",");
    if (commaPos == std::string::npos)
        throwError(lineNumber, "expected ','");

    std::string date = line.substr(0, commaPos);
    std::string value = line.substr(commaPos + 1);

    if (haveAplha(date) && lineNumber != 1)
        throwError(lineNumber, "expected only numbers");

    if (!isDateValid(date) && lineNumber != 1)
        throwError(lineNumber, "invalid date");

    if (std::count(line.begin(), line.end(), ',') != 1)
        throwError(lineNumber, "expected only 1 comma");

    if (!isValueValid(value))
        throwError(lineNumber, "invalid value");
}


bool BitcoinExchange::haveAplha(std::string str)
{
    for (size_t i = 0; i < str.size (); i++)
    {
        if (std::isalpha (str[i]))
            return true;
    }
    return false;
}



bool BitcoinExchange::isValueValid (std::string value)
{
    if (value.empty ())
        return false;
    if (std::atof (value.c_str ()) < 0)
        return false;
    return true;
}


void BitcoinExchange::throwError(size_t lineNumber, const std::string &message)
{
    std::stringstream ss;
    ss << "Database error: line " << lineNumber << ": " << message;
    throw std::runtime_error(ss.str());
}

void BitcoinExchange::trim(std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos) {
        str.clear();
        return;
    }

    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    str = str.substr(start, end - start + 1);
}

void BitcoinExchange::printData(std::ifstream &file, std::ostream &out)
{
    std::map<std::string, double>::iterator dataBaseElement;
    std::string line;

    while(std::getline(file, line))
    {
        trim(line);
        if (line == "date | value")
            continue;
        if (!validadeInputLine(line))
            continue; 
        size_t i = line.find("|");
        std::string date = line.substr(0, i);
        trim(date);

        std::string valueStr = line.substr(i + 1);
        trim(valueStr);

        double value = std::atof(valueStr.c_str());

        dataBaseElement = getNearestDate(date);
        if (dataBaseElement == _exchangeRates.end())
        {
            out << "Error: date not found in database" << std::endl;
            continue; 
        }

        out << date << " => " << valueStr << " = "
            << std::fixed << std::setprecision(2)
            << dataBaseElement->second * value << std::endl;
    }

}


std::map<std::string, double>::iterator BitcoinExchange::getNearestDate (std::string inputDate)
{
    std::map<std::string, double>::iterator it;

    it = _exchangeRates.find(inputDate);
    if (it != _exchangeRates.end ())
        return it;
    it = _exchangeRates.lower_bound(inputDate);
    it--;
    return it;
}


bool BitcoinExchange::validadeInputLine(std::string line)
{
    size_t i;

    if (line.empty())
    {
        std::cout << "Error: empty line" << std::endl;
        return false;
    }
    if (haveAplha(line))
    {
        std::cout << "Error: expected only numbers" << std::endl;
        return false;
    }
    i = line.find("|");
    if (i == std::string::npos)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    std::string date = line.substr(0, i);
    trim(date);
    if (date.empty() || !isDateValid(date))
    {
        std::cout << "Error: invalid date" << std::endl;
        return false;
    }
    std::string value = line.substr(i + 1);
    trim(value);
    if (value.empty())
    {
        std::cout << "Error: empty value" << std::endl;
        return false;
    }
    double number = std::atof(value.c_str());
    if (number < 0)
    {
        std::cout << "Error: not a positive number" << std::endl;
        return false;
    }
    if (number > 1000)
    {
        std::cout << "Error: too large a number" << std::endl;
        return false;
    }

    return true;
}