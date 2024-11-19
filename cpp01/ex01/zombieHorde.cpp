#include "Zombie.hpp"

Zombie* newZombie(int N, std::string name )
{
    return new Zombie[N];
}
