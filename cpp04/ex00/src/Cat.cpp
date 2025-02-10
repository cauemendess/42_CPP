#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << GREEN << "Cat Default constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << BOLD << "Cat Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat const &rightSide)
{
	std::cout << BOLD << "Cat Assignation operator called" << RESET << std::endl;
	this->_type = rightSide._type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << CYAN << "🐱: MEOOOOOW!!" << RESET << std::endl;
}