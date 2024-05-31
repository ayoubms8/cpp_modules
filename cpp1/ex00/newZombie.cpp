#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombi = new Zombie(name);
	return (zombi);
}