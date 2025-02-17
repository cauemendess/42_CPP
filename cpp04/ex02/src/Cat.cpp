#include "../includes/Cat.hpp"


Cat::Cat() : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << GREEN << "Cat Default constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
	delete this->_brain;
	this->_brain = NULL;
}

Cat::Cat(const Cat &copy) : AAnimal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << BOLD << "Cat Copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &rightSide)
{
	Brain	*newBrain;

	std::cout << BOLD << "Cat Assignation operator called" << RESET << std::endl;
	if (this != &rightSide)
	{
		AAnimal::operator=(rightSide);
		newBrain = new Brain(*rightSide._brain);
		delete this->_brain;
		this->_brain = newBrain;
	}
	return (*this);
}

std::string Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}

void Cat::setIdea(int index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

void Cat::makeSound(void) const
{
	std::cout << CYAN << "🐱: MEOOOOOW!!" << RESET << std::endl;
}