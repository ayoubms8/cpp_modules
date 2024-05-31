#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog const &copy)
{
	std::cout << "Dog copy assignement overload constructor called" << std::endl;
	if(this != &copy)
		type = copy.type;
	return(*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof"<< std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}