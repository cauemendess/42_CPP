#include <iostream>
#include "ClapTrap.hpp"


int main() {
    std::cout << YELLOW "Creating ClapTraps..." RESET << std::endl;
    
    ClapTrap clapTrap;
    ClapTrap clapTrap2("Jorge");
    
    std::cout << RED "\n[Attack]" RESET " No name attacks Jorge!" << std::endl;
    clapTrap.attack(clapTrap2.getName());
    clapTrap2.takeDamage(clapTrap.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " Jorge repairs himself!" << std::endl;
    clapTrap2.beRepaired(5);
    
    std::cout << RED "\n[Attack]" RESET " Jorge attacks No name!" << std::endl;
    clapTrap2.attack(clapTrap.getName());
    clapTrap.takeDamage(clapTrap2.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " No name repairs himself!" << std::endl;
    clapTrap.beRepaired(5);

    std::cout << YELLOW "\nBattle over!" RESET << std::endl;
    
    return 0;
}
