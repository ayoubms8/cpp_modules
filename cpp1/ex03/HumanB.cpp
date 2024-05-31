#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->_Weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	if (this->_Weapon)
		std::cout << this->name+" attacks with their "+this->_Weapon->getType() << std::endl;
	else
		std::cout << this->name+" can't attack!"<< std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_Weapon = &weapon;
}
