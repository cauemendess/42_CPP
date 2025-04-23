#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

const std::string RED = "\033[31m";
const std::string CYAN = "\033[36m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BOLD = "\033[1m";
const std::string BLINK = "\033[5m";
const std::string INVERSE = "\033[7m";
const std::string RESET = "\033[0m";


class Fixed
{
private:
	int _rawBits;
	static const int _fraqBits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
	int  toInt() const;
	float toFloat() const;

    // Min and Max functions
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);

	bool operator>(Fixed const &rigthSide) const;
	bool operator<(Fixed const &rigthSide) const;
	bool operator>=(Fixed const &rigthSide) const;
	bool operator<=(Fixed const &rigthSide) const;
	bool operator==(Fixed const &rigthSide) const;
	bool operator!=(Fixed const &rigthSide) const;
	Fixed operator+(Fixed const &rigthSide) const;
	Fixed operator-(Fixed const &rigthSide) const;
	Fixed operator*(Fixed const &rigthSide) const;
	Fixed operator/(Fixed const &rigthSide) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);


#endif