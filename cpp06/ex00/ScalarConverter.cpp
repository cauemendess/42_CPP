#include "ScalarConverter.hpp"

const std::string ScalarConverter::_pseudoLiterals[8] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff", "inf", "inff"};

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rightSide)
{
    (void)rightSide;
    return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

void ScalarConverter::convertChar(const std::string &str)
{
    char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertInt(const std::string &str)
{
    int i = std::stoi(str);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    printChar(c);
    printInt(i);
    printFloat(f);
    printDouble(d);
}

void ScalarConverter::convertFloat(const std::string &str)
{
    float f = std::stof(str);
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);

    printChar(c);
    printInt(i);
    printFloat(f);
    printDouble(d);
}

void ScalarConverter::convertDouble(const std::string &str)
{
    double d = std::stod(str);
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    printChar(c);
    printInt(i);
    printFloat(f);
    printDouble(d);
}

void ScalarConverter::printChar(char c)
{
    if(atol(_str.c_str()) < -128 || atol(_str.c_str()) > 127)
        std::cout << "char: impossible" << std::endl;

    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
    if (atol(_str.c_str()) < INT_MIN || atol(_str.c_str()) > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else if ( i != atol(_str.c_str()) && _type != CHAR)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
}

