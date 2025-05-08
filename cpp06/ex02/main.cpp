#include "Base.hpp"


int main(void)
{
    Base *base = generate();
    std::cout << "Identifying base class using pointer:" << std::endl;
    identify(base);
    std::cout << "Identifying base class using reference:" << std::endl;
    identify(*base);
    delete base;
    return 0;
}