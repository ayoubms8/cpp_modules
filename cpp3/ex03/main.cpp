#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap bruh("bruh");
	ClapTrap *aaaa = new DiamondTrap("aaaa");
	DiamondTrap *bb = dynamic_cast<DiamondTrap*>(aaaa);

	bruh.takeDamage(30);
	bruh.beRepaired(10);
	bb->whoAmI();
	bb->guardGate();
	bb->highFivesGuys();
	return (0);
}