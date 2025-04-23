#include "Zombie.hpp"

int main(void)
{
    std::cout << BOLD << CYAN << "=======================================" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "     Welcome to the Zombie Program      " << RESET << std::endl;
    std::cout << BOLD << CYAN << "=======================================" << RESET << std::endl;

    std::cout << std::endl << BOLD << "Creating a zombie horde:" << RESET << std::endl;

    Zombie *zombies = zombieHorde(10, "jorginho");
    delete[] zombies;

    std::cout << BOLD << CYAN << "=======================================" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "        End of Zombie Program           " << RESET << std::endl;
    std::cout << BOLD << CYAN << "=======================================" << RESET << std::endl;
    return 0;
}
