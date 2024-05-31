#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap 
{
private:
	std::string Name;
public:
	DiamondTrap();
	DiamondTrap(std::string Name);
	DiamondTrap(DiamondTrap const &copy);
	DiamondTrap &operator=(DiamondTrap const &copy);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void whoAmI();
	~DiamondTrap();
};


#endif