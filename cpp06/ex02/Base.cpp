#include "Base.hpp"
#include <iostream>

Base::~Base()
{
}


void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    identify(&p);
}

Base *generate(void)
{
    srand(time(0));
    int random = rand() % 3;
    if (random == 0)
    {
        std::cout << "A base class has been created" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "B base class has been created" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "C base class has been created" << std::endl;
        return new C();
    }
}
