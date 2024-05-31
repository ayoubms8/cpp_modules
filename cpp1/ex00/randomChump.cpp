#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie zombi = Zombie(name);
	zombi.announce();
}