#ifndef CAT_HPP
# define CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(const WrongCat &other);
    ~WrongCat();
	WrongCat &operator=(const WrongCat &rigthSide);
	void makeSound(void) const;
};

#endif