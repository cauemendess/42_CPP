#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if(this->_weapon != NULL && this->_weapon->getType() != "")
		std::cout << CYAN << this->_name << " attacks with their " << this->_weapon->getType() << RESET << std::endl;
	else
		std::cout << RED << this->_name << " has no weapon to attack." << RESET << std::endl;
}
