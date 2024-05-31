#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
public:
	FragTrap();
	FragTrap(std::string Name);
	FragTrap(FragTrap const &copy);
	FragTrap &operator=(FragTrap const &copy);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void highFivesGuys(void);
	~FragTrap();
};


#endif