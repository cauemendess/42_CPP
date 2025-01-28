#include "ClapTrap.hpp"

int main()
{
    std::cout << "Creating a no name ClapTrap and Jorge" << std::endl;
	ClapTrap clapTrap;
	ClapTrap clapTrap2("jorge");

	std::cout << "Attacking Jorge" << std::endl;
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	std::cout << "Repairing Jorge" << std::endl;
	clapTrap2.beRepaired(5);
	std::cout << "Attacking no name" << std::endl;
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	std::cout << "Repairing no name" << std::endl;
	clapTrap.beRepaired(5);
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	clapTrap2.beRepaired(5);
	clapTrap.beRepaired(5);
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	clapTrap2.beRepaired(5);
	clapTrap.beRepaired(5);
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	clapTrap2.beRepaired(5);
	clapTrap.beRepaired(5);
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
	clapTrap2.beRepaired(5);
	clapTrap.beRepaired(5);
	clapTrap.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap.getAttackDamage());
	clapTrap2.attack(clapTrap.getName());
	clapTrap.takeDamage(clapTrap2.getAttackDamage());
}
