#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitpoints(10) , energypoints(10), attackdamage(0)
{
	std::cout << "Nameless ClapTrap constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string _Name) : Name(_Name), hitpoints(10) , energypoints(10), attackdamage(0)
{
	std::cout << "ClapTrap " + Name + " constructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &copy)
{
	if (this != &copy)
	{
		Name = copy.Name;
		attackdamage = copy.attackdamage;
		energypoints = copy.energypoints;
		hitpoints = copy.hitpoints;
	}
	std::cout << "copy assignement constructor called" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!hitpoints)
	{
		std::cout << "ClapTrap " + Name + " is already dead" << std::endl;
		return ;
	}
	if (!energypoints)
	{
		std::cout << "ClapTrap " + Name + " has no energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " + Name + " attacks " + target + ", causing " << attackdamage << " points of damage!" << std::endl;
	energypoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!hitpoints)
	{
		std::cout << "ClapTrap " + Name + " is already dead" << std::endl;
		return ;
	}
	if ((unsigned int)hitpoints <= amount)
	{
		std::cout << "ClapTrap " + Name + " is dead" << std::endl;
		hitpoints = 0;
		return ;
	}
	hitpoints -= amount;
	std::cout << "ClapTrap " + Name + " takes " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!energypoints || !hitpoints)
	{
		std::cout << "ClapTrap " + Name + " can't be repaired!" << std::endl;
		return ;
	}
	energypoints--;
	hitpoints += amount;
	std::cout << "ClapTrap " + Name + " is healed for " << amount << " points!" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (Name);
}

void ClapTrap::setName(std::string _Name)
{
	Name = _Name;
}

int ClapTrap::getHitpoints() const
{
	return (hitpoints);
}

void ClapTrap::setHitpoints(int _hitpoints)
{
	hitpoints = _hitpoints;
}

int ClapTrap::getEnergypoints() const
{
	return (energypoints);
}

void ClapTrap::setEnergypoints(int _energypoints)
{
	energypoints = _energypoints;
}

int ClapTrap::getAttackdamage() const
{
	return (attackdamage);
}

void ClapTrap::setAttackdamage(int _attackdamage)
{
	attackdamage = _attackdamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " + Name + " destroyed" << std::endl;
}