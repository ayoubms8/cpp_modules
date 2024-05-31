#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
	std::cout << "WrongCat copy assignement overload constructor called" << std::endl;
	if(this != &copy)
		type = copy.type;
	return(*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow"<< std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}