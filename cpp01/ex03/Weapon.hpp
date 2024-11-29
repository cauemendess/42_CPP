#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
    std::string _type;
public:
    Weapon();
    ~Weapon();
    const std::string &getType();
    void setType(std::string type);
    
};

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}


#endif