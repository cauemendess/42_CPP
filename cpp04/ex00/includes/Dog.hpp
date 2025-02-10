#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
  public:
	Dog();
	Dog(const Dog &other);
    ~Dog();
	Dog &operator=(const Dog &rigthSide);
	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif