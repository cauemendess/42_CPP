#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *_brain;
public:
	Cat();
	Cat(const Cat &other);
	virtual ~Cat();
	Cat &operator=(const Cat &rigthSide);
	virtual void makeSound(void) const;
	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);
};

#endif