#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Creating a ScavTrap from a ClapTrap with no name with " 
            << this->_hitPoints  << " hit points, " 
            << this->_energyPoints << " energy points and " 
            << this->_attackDamage << " attack damage" << std::endl;
}


void ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " is dead and cannot attack" << std::endl;
		return;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " has no energy points and cannot attack" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name 
			  << " attacks " << target
			  << ", causing " << this->_attackDamage
			  << " points of damage and now have "
			  << this->_energyPoints 
			  << " energy points" << std::endl;
}


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " was created from a ClapTrap with "
			<< _hitPoints << " hit points, "
			<< _energyPoints << " energy points and "
			<< _attackDamage << " attack damage" << std::endl;
}



ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) 
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rightSide)
{
	std::cout << "Assignation operator called" << std::endl;
    if (this != &rightSide) {
        ClapTrap::operator=(rightSide);
        this->_name = rightSide._name;
        this->_hitPoints = rightSide._hitPoints;
        this->_energyPoints = rightSide._energyPoints;
        this->_attackDamage = rightSide._attackDamage;
    }
    return *this;
}

int ScavTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

std::string ScavTrap::getName(void) const
{
	return (this->_name);
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " <<  this->_name << " has entered in Gate keeper mode" << std::endl;
}