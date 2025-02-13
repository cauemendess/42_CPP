#include "../includes/WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << GREEN << "WrongCat Default constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat Destructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << BOLD << "WrongCat Copy constructor called" << RESET << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &rightSide)
{
	std::cout << BOLD << "WrongCat Assignation operator called" << RESET << std::endl;
	this->_type = rightSide._type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << CYAN << "**Fake cat**" << RESET << std::endl;
}