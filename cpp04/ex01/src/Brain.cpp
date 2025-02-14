#include "Brain.hpp"


void	Brain::generateIdeas()
{
	std::string ideas[5] = 
	{
		"AAAAaa",
		"BBBbbb",
		"CCCccc",
		"DDDDDd",
		"EEEEEe"
	};
	for(int i = 0; i < 100; i++)
	{
		this->_ideas[i] = ideas[rand() % 6];
	}
}


Brain::Brain()
{
	generateIdeas();
	std::cout << GREEN << "Brain Default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << GREEN << "Brain copy constructor called" << RESET << std::endl;
	*this = other;
}


Brain &Brain::operator=(Brain const &rightSide)
{
	std::cout << BOLD << "Brain Assignation operator called" << RESET << std::endl;
	for(int i = 0; i < 100; i++)
	{
		this->_ideas[i] = rightSide._ideas[i];
	}
	return (*this);
}

