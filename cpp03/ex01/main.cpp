#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"

int main() {
    std::cout << YELLOW "Creating ClapTrap and ScavTrap..." RESET << std::endl;
    
    ClapTrap clapTrap("Clap");
    ScavTrap scavTrap("Scav");
    
    std::cout << RED "\n[Attack]" RESET " ClapTrap attacks ScavTrap!" << std::endl;
    clapTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(clapTrap.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " ScavTrap repairs himself!" << std::endl;
    scavTrap.beRepaired(5);
    
    std::cout << RED "\n[Attack]" RESET " ScavTrap attacks ClapTrap!" << std::endl;
    scavTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(scavTrap.getAttackDamage());
    
    std::cout << YELLOW "\nBattle over!" RESET << std::endl;
    
    scavTrap.guardGate();
    
    std::cout << YELLOW "\nDestructors!" RESET << std::endl;
    
    return 0;
}

