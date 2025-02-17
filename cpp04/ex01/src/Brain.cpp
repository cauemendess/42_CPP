#include "../includes/Brain.hpp"


Brain::~Brain()
{
	std::cout << RED << "Brain Destructor called" << RESET << std::endl;
}

Brain::Brain()
{
	std::string ideas[5] = 
	{
   		"Chasing my tail!",
        "Where did I bury that bone?",
        "Time for a nap... again.",
        "Maybe the cat is actually nice?",
        "Squirrel!!!"
	};
	for(int i = 0; i < 100; i++)
	{
		this->_ideas[i] = ideas[rand() % 5];
	}
	std::cout << GREEN << "Brain Default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << GREEN << "Brain copy constructor called" << RESET << std::endl;
	*this = other;
}


Brain &Brain::operator=(const Brain &rightSide)
{
	std::cout << BOLD << "Brain Assignation operator called" << RESET << std::endl;
	for(int i = 0; i < 100; i++)
	{
		this->_ideas[i] = rightSide._ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index > 100)
		return ("Must be < 0 or > 100");
	return (this->_ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index > 100)
		return ;
	this->_ideas[index] = idea;
}
