
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
  public:
	Cat();
	Cat(std::string name);
	Cat(const Cat &other);
    ~Cat();
	Cat &operator=(const Cat &rigthSide);
	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif