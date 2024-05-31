#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
private:
	std::string name;
public:
	void announce(void);
	Zombie(std::string name);
	void setName(std::string name);
	std::string getName(void);
	Zombie();
	~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif