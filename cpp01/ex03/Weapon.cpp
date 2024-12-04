#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string const &Weapon::getType()
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

const std::string &Weapon::getType()
{
	return(this->_type);
}

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{
}