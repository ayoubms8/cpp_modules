#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->setAttackdamage(30);
	this->setEnergypoints(100);
	this->setHitpoints(100);
	std::cout << "Nameless FragTrap constructed" << std::endl;
}

FragTrap::FragTrap(std::string _Name)
{
	this->setName(_Name);
	this->setAttackdamage(30);
	this->setEnergypoints(100);
	this->setHitpoints(100);
	std::cout << "FragTrap " + this->getName() + " constructed" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy)
{
	*this = copy;
	std::cout << "copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
	if (this != &copy)
	{
		this->setName(copy.getName());
		this->setAttackdamage(copy.getAttackdamage());
		this->setEnergypoints(copy.getEnergypoints());
		this->setHitpoints(copy.getHitpoints());
	}
	std::cout << "copy assignement constructor called" << std::endl;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (!this->getHitpoints())
	{
		std::cout << "FragTrap " + this->getName() + " is already dead" << std::endl;
		return ;
	}
	if (!this->getEnergypoints())
	{
		std::cout << "FragTrap " + this->getName() + " has no energy" << std::endl;
		return ;
	}
	std::cout << "FragTrap " + this->getName() + " attacks " + target + ", causing " << this->getAttackdamage() << " points of damage!" << std::endl;
	this->setEnergypoints(this->getEnergypoints() - 1);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (!this->getHitpoints())
	{
		std::cout << "FragTrap " + this->getName() + " is already dead" << std::endl;
		return ;
	}
	if ((unsigned int)this->getHitpoints() <= amount)
	{
		std::cout << "FragTrap " + this->getName() + " is dead" << std::endl;
		this->setHitpoints(0);
		return ;
	}
	this->setHitpoints(this->getHitpoints() - amount);
	std::cout << "FragTrap " + this->getName() + " takes " << amount << " points of damage!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (!this->getEnergypoints() || !this->getHitpoints())
	{
		std::cout << "ScavTrap " + this->getName() + " can't be repaired!" << std::endl;
		return ;
	}
	this->setEnergypoints(this->getEnergypoints() - 1);
	this->setHitpoints(this->getHitpoints() + amount);
	std::cout << "FragTrap " + this->getName() + " is healed for " << amount << " points!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " + this->getName() + " wants to high five!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " + this->getName() + " destroyed" << std::endl;
}