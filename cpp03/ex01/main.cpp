#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << YELLOW "Creating ClapTraps and ScavTraps..." RESET << std::endl;
    
    ClapTrap clapTrap;
    ClapTrap clapTrap2("Carlos");
    ScavTrap scavTrap;
    ScavTrap scavTrap2("Jorge");
    
    std::cout << RED "\n[Attack]" RESET " No name ClapTrap attacks Carlos!" << std::endl;
    clapTrap.attack(clapTrap2.getName());
    clapTrap2.takeDamage(clapTrap.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " Carlos repairs himself!" << std::endl;
    clapTrap2.beRepaired(5);
    
    std::cout << RED "\n[Attack]" RESET " No name ScavTrap attacks Jorge!" << std::endl;
    scavTrap.attack(scavTrap2.getName());
    scavTrap2.takeDamage(scavTrap.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " Jorge repairs himself!" << std::endl;
    scavTrap2.beRepaired(5);
    
    std::cout << RED "\n[Attack]" RESET " Jorge attacks No name ScavTrap!" << std::endl;
    scavTrap2.attack(scavTrap.getName());
    scavTrap.takeDamage(scavTrap2.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " No name ScavTrap repairs himself!" << std::endl;
    scavTrap.beRepaired(5);
    
    std::cout << YELLOW "\nBattle over!" RESET << std::endl;
    scavTrap2.guardGate();

    std::cout << YELLOW "\nDestructors!" RESET << std::endl;

    return 0;
}

