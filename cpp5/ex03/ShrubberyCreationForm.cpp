#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Aform("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Aform("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : Aform(copy), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	if (this != &copy)
	{
		Aform::operator=(copy);
	}
	return (*this);
}

std::string const	&ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void				ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!this->getSigned())
			throw Aform::NotSignedException();
		if (this->getGradeToExecute() < executor.getGrade())
			throw Aform::GradeTooLowException();
		std::ofstream out;
		out.open((this->_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
		out << "     Tree  \n";
		out << "      /\\\n";
		out << "     /**\\\n";
		out << "    /****\\\n";
		out << "      ||\n";
		out << "      ||\n";
		out << "     Tree  ";
		out << std::endl;
		out.close();
	}
	catch (std::exception &e)
	{
		std::cout << executor.getName() << " cannot execute " << this->getName() << " because " << e.what() << std::endl;
		return ;
	}
}