#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
public:
	ScavTrap();
	ScavTrap(std::string Name);
	ScavTrap(ScavTrap const &copy);
	ScavTrap &operator=(ScavTrap const &copy);
	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
	void guardGate();
	virtual ~ScavTrap();
};


#endif