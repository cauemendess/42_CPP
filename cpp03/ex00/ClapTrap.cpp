#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("NoNameTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "A default ClapTrap with no name was created with " << _hitPoints << " hit points, " << _energyPoints << " energy points and " <<_attackDamage << " attack damage" << std::endl;
}


ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap " << _name << " was created with " << _hitPoints << " hit points, " << _energyPoints << " energy points and " << _attackDamage << " attack damage" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}


int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}


ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}