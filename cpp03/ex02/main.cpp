#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"

int main() {
    std::cout << YELLOW "Creating ClapTrap, ScavTrap, and FragTrap..." RESET << std::endl;
    
    ClapTrap clapTrap("Clap");
    ScavTrap scavTrap("Scav");
    FragTrap fragTrap("Frag");
    
    std::cout << RED "\n[Attack]" RESET " ClapTrap attacks ScavTrap!" << std::endl;
    clapTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(clapTrap.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " ScavTrap repairs himself!" << std::endl;
    scavTrap.beRepaired(5);
    
    std::cout << RED "\n[Attack]" RESET " ScavTrap attacks FragTrap!" << std::endl;
    scavTrap.attack(fragTrap.getName());
    fragTrap.takeDamage(scavTrap.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " FragTrap repairs himself!" << std::endl;
    fragTrap.beRepaired(5);
    
    std::cout << RED "\n[Attack]" RESET " FragTrap attacks ClapTrap!" << std::endl;
    fragTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(fragTrap.getAttackDamage());
    
    std::cout << YELLOW "\nBattle over!" RESET << std::endl;
    
    scavTrap.guardGate();
    fragTrap.highFivesGuys();
    
    std::cout << YELLOW "\nDestructors!" RESET << std::endl;
    
    return 0;
}

