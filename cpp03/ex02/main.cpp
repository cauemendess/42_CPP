#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void battleSequence(ClapTrap& attacker, ClapTrap& defender) 
{
    std::cout << RED "\n[ATTACK] " RESET << attacker.getName() << " attacks " << defender.getName() << "!" << std::endl;
    attacker.attack(defender.getName());
    defender.takeDamage(attacker.getAttackDamage());
    std::cout << GREEN "[REPAIR] " RESET << defender.getName() << " repairs himself!" << std::endl;
    defender.beRepaired(5);
}

int main() {
    std::cout << INVERSE "CREATING GOKU (CLAPTRAP)" RESET << std::endl;
    ClapTrap Goku("Goku");

    std::cout << INVERSE "CREATING VEGETA (SCAVTRAP)" RESET << std::endl;
    ScavTrap Vegeta("Vegeta");

    std::cout << INVERSE "CREATING GOHAN (FRAGTRAP)" RESET << std::endl;
    FragTrap Gohan("Gohan");

    std::cout << YELLOW "\n--- BATTLE STARTS ---" RESET << std::endl;

    std::cout << INVERSE "ROUND 1: GOKU vs VEGETA" RESET << std::endl;
    battleSequence(Goku, Vegeta);
    battleSequence(Vegeta, Goku);
    
    std::cout << INVERSE "ROUND 2: VEGETA vs GOHAN" RESET << std::endl;
    battleSequence(Vegeta, Gohan);
    battleSequence(Gohan, Vegeta);

    std::cout << INVERSE "ROUND 3: GOHAN vs GOKU" RESET << std::endl;
    battleSequence(Gohan, Goku);
    battleSequence(Goku, Gohan);

    std::cout << INVERSE "THE FIGHT IS OVER! TIME TO TEAM UP!" RESET << std::endl;
    Vegeta.guardGate();
    Gohan.highFivesGuys();

    std::cout << YELLOW "\n--- BATTLE OVER ---" RESET << std::endl;

    return 0;
}


