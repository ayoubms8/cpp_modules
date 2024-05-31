#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(Brain const &copy)
{
	std::cout << "Brain copy assignement overload constructor called" << std::endl;
	if (this != &copy)
	{
		for (size_t i = 0; i < 100; i++)
		{
			ideas[i] = copy.ideas[i];
		}
	}
	return *this;
}