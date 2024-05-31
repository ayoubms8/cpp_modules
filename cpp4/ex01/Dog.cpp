#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_brain = new Brain();
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
	{
		this->_brain = copy._brain;
		type = copy.type;
	}
	return(*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof"<< std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}