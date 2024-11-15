#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << GREEN << _name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

Zombie::~Zombie()
{
    std::cout << RED << "Zombie " << _name << " is being destroyed." << RESET << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->_name = name;
}
