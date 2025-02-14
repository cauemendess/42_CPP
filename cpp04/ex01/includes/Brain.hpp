#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain *other);
	void generateIdeas();
	~Brain();
};


#endif