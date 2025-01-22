#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(const Fixed& other)
{
	this->_rawBits = other._rawBits;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_rawBits);
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->_rawBits = other.getRawBits();
	return(*this);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return(out);
}


Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = value << this->_fraqBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(value * (1 << this->_fraqBits));
}

float Fixed::toFloat() const
{
    return ((float)this->_rawBits / (1 << this->_fraqBits));
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fraqBits);
}

bool Fixed::operator>(Fixed const &rigthSide) const
{
	return (this->_rawBits > rigthSide.getRawBits());
}

bool Fixed::operator<(Fixed const &rigthSide) const
{
	return (this->_rawBits < rigthSide.getRawBits());
}

bool Fixed::operator>=(Fixed const &rigthSide) const
{
	return (this->_rawBits >= rigthSide.getRawBits());
}

bool Fixed::operator<=(Fixed const &rigthSide) const
{
	return (this->_rawBits <= rigthSide.getRawBits());
}

bool Fixed::operator==(Fixed const &rigthSide) const
{
	return (this->_rawBits == rigthSide.getRawBits());
}

bool Fixed::operator!=(Fixed const &rigthSide) const
{
	return (this->_rawBits != rigthSide.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rigthSide) const
{
	return (Fixed(this->toFloat() + rigthSide.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rigthSide) const
{
	return (Fixed(this->toFloat() - rigthSide.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rigthSide) const
{
	return (Fixed(this->toFloat() * rigthSide.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rigthSide) const
{
	return (Fixed(this->toFloat() / rigthSide.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed preIncrement(*this);
	operator++();
	return (preIncrement);
}

Fixed &Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed preDecrement(*this);
	operator--();
	return (preDecrement);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}