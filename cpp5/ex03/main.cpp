#include "Bureaucrat.hpp"
#include "Aform.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	Bureaucrat bureaucrat("Bureaucrat007", 1);
	Aform *form;

	try
	{
		form = intern.makeForm("Robotomy request", "Bureaucrat007");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		form = intern.makeForm("Shrubbery creation", "Bureaucrat007");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		form = intern.makeForm("Presidential pardon", "Bureaucrat007");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}