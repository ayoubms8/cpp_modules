#include "FragTrap.hpp"

int main(void)
{
	FragTrap Player("Player");
	Player.attack("Enemy");
	Player.takeDamage(10);
	Player.beRepaired(10);
	FragTrap Player1(Player);
	Player1.attack("Enemy1");
	Player1.takeDamage(10);
	Player1.beRepaired(10);
	Player.highFivesGuys();
}