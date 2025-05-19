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

void ScalarConverter::convert(const std::string &str)
{
    if(checkType(str))
        return ;
    switch (_type)
    {
    case PSEUDO:
        printPseudo();
        break;
    case CHAR:
        convertChar(str);
        break;
    case INT:
        convertInt(str);
        break;
    case FLOAT:
        convertFloat(str);
        break;
    case DOUBLE:
        convertDouble(str);
        break;
    }
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
    int i = atoi(str.c_str());
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
    float f = atof(str.c_str());
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
    double d = atof(str.c_str());
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

    else if (std::isprint(c))
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

void ScalarConverter::printDouble(double d)
{
    
    if (atol(_str.c_str()) < INT_MIN || atol(_str.c_str()) > INT_MAX)
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printFloat(float f)
{
    if (atol(_str.c_str()) < INT_MIN || atol(_str.c_str()) > INT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

bool ScalarConverter::checkType(const std::string &str)
{
	_str = str;
	int i = 0;

	while (i < 8)
	{
		if (str == _pseudoLiterals[i])
		{
			_type = PSEUDO;
			return false;
		}
		i++;
	}
	if (str.length() == 1 && !isdigit(str[0]))
	{
		_type = CHAR;
		return false;
	}
	if (checkInt(str))
		return true;
	return false;
}

bool ScalarConverter::checkInt(const std::string &str)
{
	int i = 0;
	int dot = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < (int)str.length())
	{
		if (str[i] == '.')
        {
            dot++;
            if (dot > 1)
            {
                std::cout << "Error: invalid input" << std::endl;
                return true;
            }
        }
        else if (!isdigit(str[i]) && !(str[i] == 'f' && i == (int)str.length() - 1))
        {
            std::cout << "Error: invalid input" << std::endl;
            return true;
        }
			i++;
	}
	if (dot == 0 && str[str.length() - 1] == 'f')
	{
		std::cout << "Error: invalid input" << std::endl;
		return true;
	}	
	else if (dot == 1)
		_type = (str[str.length() - 1] == 'f') ? FLOAT : DOUBLE;
	else
		_type = INT;
	return false;
}

void ScalarConverter::printPseudo()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (_str == "nan" || _str == "nanf")
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
	else if (_str == "+inf" || _str == "+inff" || _str == "inf" || _str == "inff")
		{
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
		}
	else if (_str == "-inf" || _str == "-inff")
		{
			std::cout << "float: -inff" <<  std::endl;
			std::cout << "double: -inf" <<  std::endl;
		}
}

int ScalarConverter::_type = PSEUDO;
std::string ScalarConverter::_str = "";