#include "ClapTrap.hpp"



int main() 
{
    std::cout << YELLOW "Creating ClapTraps..." RESET << std::endl;
    ClapTrap clapTrap;
    ClapTrap clapTrap2("Arnaldo");
    
    std::cout << RED "\n[Attack]" RESET " No name attacks Arnaldo!" << std::endl;
    clapTrap.attack(clapTrap2.getName());
    clapTrap2.takeDamage(clapTrap.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " Arnaldo repairs himself!" << std::endl;
    clapTrap2.beRepaired(5);
    
    std::cout << RED "\n[Attack]" RESET " Arnaldo attacks No name!" << std::endl;
    clapTrap2.attack(clapTrap.getName());
    clapTrap.takeDamage(clapTrap2.getAttackDamage());
    
    std::cout << GREEN "\n[Repair]" RESET " No name repairs himself!" << std::endl;
    clapTrap.beRepaired(5);
    
    return 0;
}