#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->setAttackdamage(30);
	this->setEnergypoints(50);
	this->setHitpoints(100);
	std::cout << "Nameless DiamondTrap constructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _Name)
{
	this->Name = _Name;
	this->setName(_Name + "_clap_name");
	this->setAttackdamage(30);
	this->setEnergypoints(50);
	this->setHitpoints(100);
	std::cout << "DiamondTrap " + this->Name + " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy)
{
	*this = copy;
	std::cout << "copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &copy)
{
	if (this != &copy)
	{
		this->Name = copy.Name;
		this->setName(copy.getName());
		this->setAttackdamage(copy.getAttackdamage());
		this->setEnergypoints(copy.getEnergypoints());
		this->setHitpoints(copy.getHitpoints());
	}
	std::cout << "copy assignement constructor called" << std::endl;
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (!this->getHitpoints())
	{
		std::cout << "DiamondTrap " + this->Name + " is already dead" << std::endl;
		return ;
	}
	if ((unsigned int)this->getHitpoints() <= amount)
	{
		std::cout << "DiamondTrap " + this->Name + " is dead" << std::endl;
		this->setHitpoints(0);
		return ;
	}
	this->setHitpoints(this->getHitpoints() - amount);
	std::cout << "DiamondTrap " + this->Name + " takes " << amount << " points of damage!" << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (!this->getEnergypoints() || !this->getHitpoints())
	{
		std::cout << "DiamondTrap " + this->getName() + " can't be repaired!" << std::endl;
		return ;
	}
	this->setEnergypoints(this->getEnergypoints() - 1);
	this->setHitpoints(this->getHitpoints() + amount);
	std::cout << "DiamondTrap " + this->Name + " is healed for " << amount << " points!" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " + this->Name + " is " + this->getName() << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " + this->Name + " destroyed" << std::endl;
}