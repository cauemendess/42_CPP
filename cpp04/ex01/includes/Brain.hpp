#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &rightSide);
	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);
	~Brain();
};


#endif