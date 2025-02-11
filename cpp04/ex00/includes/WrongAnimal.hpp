#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"


class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
    std::string getType(void) const;
	void makeSound() const;
    Animal &operator=(const Animal &rigthSide);

	~WrongAnimal();
};


#endif