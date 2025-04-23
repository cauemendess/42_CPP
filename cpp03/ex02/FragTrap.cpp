#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Creating a FragTrap from a ClapTrap with no name with " 
	<< this->_hitPoints << " hit points, "
 	<< this->_energyPoints << " energy points and " 
	<< this->_attackDamage << " attack damage"  << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " was created from a ClapTrap with "
			<< _hitPoints << " hit points, "
			<< _energyPoints << " energy points and "
			<< _attackDamage << " attack damage"  << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout  << "FragTrap Destructor called"  << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) 
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = copy;
}

FragTrap &FragTrap::operator=(FragTrap const &rightSide)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
    if (this != &rightSide) {
        ClapTrap::operator=(rightSide);
        this->_name = rightSide._name;
        this->_hitPoints = rightSide._hitPoints;
        this->_energyPoints = rightSide._energyPoints;
        this->_attackDamage = rightSide._attackDamage;
    }
    return *this;
}

int FragTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

std::string FragTrap::getName(void) const
{
	return (this->_name);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a high five" << std::endl;
}