#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <limits.h>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>
# include <cfloat>

enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO
};

class ScalarConverter
{
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &rightSide);
	~ScalarConverter();
	static void convertChar(const std::string &str);
	static void convertInt(const std::string &str);
	static void convertFloat(const std::string &str);
	static void convertDouble(const std::string &str);
	static bool checkType(const std::string &str);
	static bool checkInt(const std::string &str);

	static void printPseudo();
	static void printChar(char c);
	static void printInt(int i);
	static void printFloat(float f);
	static void printDouble(double d);

	static const std::string _pseudoLiterals[8];
	static int _type;
	static std::string _str;
public:
    static void convert(const std::string &str);

};

#endif