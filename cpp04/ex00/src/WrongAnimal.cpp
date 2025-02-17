#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Human")
{
	std::cout << GREEN << "WrongAnimal Default constructor called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal Default destructor called" << RESET << std::endl;
}


WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << BOLD << "WrongAnimal Copy constructor called" << RESET << std::endl;
	*this = other;
}


WrongAnimal::WrongAnimal(std::string name) : _type(name)
{
	std::cout << GREEN << "Creating a WrongAnimal from the type: " << this->_type << RESET << std::endl;
}


WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rightSide)
{
	std::cout << BOLD << "WrongAnimal Assignation operator called" << RESET << std::endl;
	this->_type = rightSide._type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << CYAN << "😁: Hello!" << RESET << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}