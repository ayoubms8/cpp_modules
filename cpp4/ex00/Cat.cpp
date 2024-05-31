#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << "Cat copy assignement overload constructor called" << std::endl;
	if(this != &copy)
		type = copy.type;
	return(*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow"<< std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}