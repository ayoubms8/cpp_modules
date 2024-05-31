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
	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
	std::string getName() const;
	void setName(std::string Name);
	int getHitpoints() const;
	void setHitpoints(int hitpoints);
	int getEnergypoints() const;
	void setEnergypoints(int energypoints);
	int getAttackdamage() const;
	void setAttackdamage(int attackdamage);
	virtual ~ClapTrap();
};


#endif