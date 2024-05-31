#include "Zombie.hpp"

int main(void)
{
	Zombie *zombi = newZombie("bruuuuh");
	zombi->announce();
	randomChump("BRUUUUUUUH");
	delete zombi;
}