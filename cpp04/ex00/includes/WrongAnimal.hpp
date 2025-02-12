#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"


class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string name);
	WrongAnimal(const WrongAnimal &other);
    std::string getType(void) const;
	void makeSound() const;
	WrongAnimal &operator=(const WrongAnimal &rightSide);

	~WrongAnimal();
};


#endif