#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_Weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
	std::cout << this->name+" attacks with their "+this->_Weapon.getType() << std::endl;
}
