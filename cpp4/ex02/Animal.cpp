#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(Animal const &copy)
{
	std::cout << "Animal copy assignement overload constructor called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->type);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
