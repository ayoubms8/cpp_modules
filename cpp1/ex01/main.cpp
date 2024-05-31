#include "Zombie.hpp"

int main(void)
{
	int i = 0;
	Zombie *zombi = zombieHorde(-5, "BRUUUUUUUH");
	while (i < 10)
	{
		zombi[i].announce();
		i++;
	}
	delete [] zombi;
}