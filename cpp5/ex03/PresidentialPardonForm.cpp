#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Aform("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Aform("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : Aform(copy), _target(copy._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	if (this != &copy)
	{
		Aform::operator=(copy);
	}
	return (*this);
}

std::string const	&PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void				PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!this->getSigned())
			throw Aform::NotSignedException();
		if (this->getGradeToExecute() < executor.getGrade())
			throw Aform::GradeTooLowException();
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << executor.getName() << " cannot execute " << this->getName() << " because " << e.what() << std::endl;
		return ;
	}
}