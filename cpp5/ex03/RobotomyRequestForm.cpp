#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Aform("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Aform("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : Aform(copy), _target(copy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	if (this != &copy)
	{
		Aform::operator=(copy);
	}
	return (*this);
}

std::string const	&RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void				RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!this->getSigned())
			throw Aform::NotSignedException();
		if (this->getGradeToExecute() < executor.getGrade())
			throw Aform::GradeTooLowException();
		std::srand(std::time(0));
		int r = std::rand();
		if (r % 3 || r % 2)
		{
			std::cout << "drilling noises" << std::endl;
			std::cout << "drilling noises" << std::endl;
			std::cout << "drilling noise" << std::endl;
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		}
		else
		{
			std::cout << "drilling noises" << std::endl;
			std::cout << "drilling noises" << std::endl;
			std::cout << this->_target << "'s robotomy failed" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << executor.getName() << " cannot execute " << this->getName() << " because " << e.what() << std::endl;
		return ;
	}
}