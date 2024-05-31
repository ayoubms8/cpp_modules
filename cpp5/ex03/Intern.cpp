#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(Intern const &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Aform	*Intern::makeForm(std::string const &name, std::string const &target) const
{
	int i;
	std::string form_names[] = {
		"Robotomy request",
		"Shrubbery creation",
		"Presidential pardon"
	};
	for (i = 0; i <= 3; i++)
	{
		if (name == form_names[i])
			break;
	}
	switch (i)
	{
	case 0:
		return new RobotomyRequestForm(target);
		break;
	case 1:
		return new ShrubberyCreationForm(target);
		break;
	case 2:
		return new PresidentialPardonForm(target);
		break;
	default:
		std::cout << "form not found!" << std::endl;
	}
	return NULL;
}
