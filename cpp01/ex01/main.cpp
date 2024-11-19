#include "Zombie.hpp"

int main(void)
{
    std::cout << BOLD << CYAN << "=======================================" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "     Welcome to the Zombie Program      " << RESET << std::endl;
    std::cout << BOLD << CYAN << "=======================================" << RESET << std::endl;

    std::cout << std::endl << BOLD << "Creating a static Zombie:" << RESET << std::endl;
    randomChump("Carlito");

    std::cout << std::endl << BOLD << "Creating a dynamic Zombie:" << RESET << std::endl;
    Zombie* dynamicZombie = newZombie("Rodolfo");
    dynamicZombie->announce();
    delete dynamicZombie;

    std::cout << BOLD << CYAN << "=======================================" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "        End of Zombie Program           " << RESET << std::endl;
    std::cout << BOLD << CYAN << "=======================================" << RESET << std::endl;
    return 0;
}
