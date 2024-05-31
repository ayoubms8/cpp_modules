#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
public:
	FragTrap();
	FragTrap(std::string Name);
	FragTrap(FragTrap const &copy);
	FragTrap &operator=(FragTrap const &copy);
	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
	void highFivesGuys(void);
	virtual ~FragTrap();
};


#endif