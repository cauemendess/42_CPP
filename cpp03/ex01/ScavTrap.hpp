#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &copy);
    void guardGate();
    ScavTrap &operator=(const ScavTrap &rigthSide);
    std::string getName() const;
    int getAttackDamage() const;
    ~ScavTrap();
};


#endif