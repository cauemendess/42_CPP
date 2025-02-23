#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat &other);
    virtual ~Cat();
	Cat &operator=(const Cat &rigthSide);
	virtual void makeSound(void) const;
};

#endif