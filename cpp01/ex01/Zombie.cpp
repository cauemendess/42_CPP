#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << GREEN << _name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}

Zombie::~Zombie(void)
{
    std::cout << RED << "Zombie " << _name << " is being destroyed." << RESET << std::endl;
}

Zombie::Zombie(void)
{
    return ;
}
