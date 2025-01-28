#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("NoNameTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "A default ClapTrap with no name was created with " << _hitPoints << " hit points, " << _energyPoints << " energy points and " <<_attackDamage << " attack damage" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap " << _name << " was created with " << _hitPoints << " hit points, " << _energyPoints << " energy points and " << _attackDamage << " attack damage" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack" << std::endl;
		return;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points and cannot attack" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage and now has " << this->_energyPoints << " energy points" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rightSide)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name = rightSide._name;
	this->_hitPoints = rightSide._hitPoints;
	this->_energyPoints = rightSide._energyPoints;
	this->_attackDamage = rightSide._attackDamage;
	return (*this);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " <<  this->_name << " takes " << amount << " points of damage and now has " << this->_hitPoints << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot be repaired" << std::endl;
		return;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points and cannot be repaired" << std::endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points and now has " << this->_hitPoints << " hit points and " << this->_energyPoints << " energy points" << std::endl;
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