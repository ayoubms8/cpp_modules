#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->setHitpoints(100);
	this->setEnergypoints(50);
	this->setAttackdamage(20);
	std::cout << "Nameless ScavTrap constructed" << std::endl;
}

ScavTrap::ScavTrap(std::string _Name)
{
	this->setName(_Name);
	this->setHitpoints(100);
	this->setEnergypoints(50);
	this->setAttackdamage(20);
	std::cout << "ScavTrap " + this->getName() + " constructed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
	*this = copy;
	std::cout << "copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
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

void	ScavTrap::attack(const std::string &target)
{
	if (!this->getHitpoints())
	{
		std::cout << "ScavTrap " + this->getName() + " is already dead" << std::endl;
		return ;
	}
	if (!this->getEnergypoints())
	{
		std::cout << "ScavTrap " + this->getName() + " has no energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " + this->getName() + " attacks " + target + ", causing " << this->getAttackdamage() << " points of damage!" << std::endl;
	this->setEnergypoints(this->getEnergypoints() - 1);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (!this->getHitpoints())
	{
		std::cout << "ScavTrap " + this->getName() + " is already dead" << std::endl;
		return ;
	}
	if ((unsigned int)this->getHitpoints() <= amount)
	{
		std::cout << "ScavTrap " + this->getName() + " is dead" << std::endl;
		this->setHitpoints(0);
		return ;
	}
	this->setHitpoints(this->getHitpoints() - amount);
	std::cout << "ScavTrap " + this->getName() + " takes " << amount << " points of damage!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (!this->getEnergypoints() || !this->getHitpoints())
	{
		std::cout << "ScavTrap " + this->getName() + " can't be repaired!" << std::endl;
		return ;
	}
	this->setEnergypoints(this->getEnergypoints() - 1);
	this->setHitpoints(this->getHitpoints() + amount);
	std::cout << "ScavTrap " + this->getName() + " is healed for " << amount << " points!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " + this->getName() + " has entered in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " + this->getName() + " destroyed" << std::endl;
}