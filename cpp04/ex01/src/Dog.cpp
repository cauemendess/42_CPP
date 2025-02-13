#include "../includes/Dog.hpp"


Dog::Dog() : Animal("Dog")
{
	std::cout << GREEN << "Dog Default constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog Destructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << BOLD << "Dog Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const &rightSide)
{
	std::cout << BOLD << "Dog Assignation operator called" << RESET << std::endl;
	this->_type = rightSide._type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << CYAN << "🐶: BARK! BARK!" << RESET << std::endl;
}
