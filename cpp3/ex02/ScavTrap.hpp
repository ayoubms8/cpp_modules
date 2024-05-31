#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap();
	ScavTrap(std::string Name);
	ScavTrap(ScavTrap const &copy);
	ScavTrap &operator=(ScavTrap const &copy);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate();
	~ScavTrap();
};


#endif