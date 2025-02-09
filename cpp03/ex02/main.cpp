#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main() {
    std::cout << YELLOW "Creating ClapTraps, ScavTraps, and FragTraps..." RESET << std::endl;
    
    ClapTrap clapTrap;
    ClapTrap clapTrap2("Carlos");
    ScavTrap scavTrap;
    ScavTrap scavTrap2("Jorge");
    FragTrap fragTrap;
    FragTrap fragTrap2("Luis");
    
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
    
    std::cout << RED "\n[Attack]" RESET " No name FragTrap attacks Luis!" << std::endl;
    fragTrap.attack(fragTrap2.getName());
    fragTrap2.takeDamage(fragTrap.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " Luis repairs himself!" << std::endl;
    fragTrap2.beRepaired(5);
    
    std::cout << RED "\n[Attack]" RESET " Luis attacks No name FragTrap!" << std::endl;
    fragTrap2.attack(fragTrap.getName());
    fragTrap.takeDamage(fragTrap2.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " No name FragTrap repairs himself!" << std::endl;
    fragTrap.beRepaired(5);
    
    std::cout << YELLOW "\nBattle over!" RESET << std::endl;
    
    scavTrap.guardGate();
    fragTrap.highFivesGuys();

    std::cout << YELLOW "\nDestructors!" RESET << std::endl;

    return 0;
}

