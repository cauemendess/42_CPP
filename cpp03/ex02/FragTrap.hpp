#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

// Class declaration
class FragTrap : public ClapTrap
{
  public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	~FragTrap();
	FragTrap &operator=(const FragTrap &rigthSide);
	void attack(std::string const &target);
	void highFivesGuys(void);
	std::string getName(void) const;
	int getAttackDamage(void) const;
};

#endif