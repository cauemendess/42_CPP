#include "./includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("DogCat")
{
	std::cout << GREEN << "AAnimal Default constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(std::string name) : _type(name)
{
	std::cout << GREEN << "Creating a animal from the type: " << BOLD << this->_type << RESET << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal Destructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << BOLD << "AAnimal Copy constructor called" << RESET << std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(AAnimal const &rightSide)
{
	std::cout << BOLD << "AAnimal Assignation operator called" << RESET << std::endl;
	this->_type = rightSide._type;
	return (*this);
}

void AAnimal::makeSound(void) const
{
	std::cout << CYAN << "**Generic noise**" << RESET << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}