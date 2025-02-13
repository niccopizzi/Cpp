#include "HumanB.hpp"

HumanB::HumanB(std::string theName)
{
    name = theName;
    armed = false;
}

HumanB::~HumanB()
{
    //std::cout << "Destroying human " << name << std::endl;
}

void    HumanB::setWeapon(Weapon &theWeapon)
{
    this->theWeapon = &theWeapon;
    armed = true;
}

void    HumanB::attack()
{
    if (armed)
        std::cout << name << " attacks with their " << theWeapon->getType() << std::endl;
}
