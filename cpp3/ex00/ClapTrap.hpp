#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
private:
	std::string Name;
	int			hitpoints;
	int			energypoints;
	int			attackdamage;
public:
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap &operator=(ClapTrap const &copy);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};


#endif