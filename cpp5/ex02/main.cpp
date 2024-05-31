#include "Bureaucrat.hpp"
#include "Aform.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	Bureaucrat01("Bureaucrat01", 1);
	Bureaucrat	Bureaucrat02("Bureaucrat02", 150);
	ShrubberyCreationForm	shrubberyCreationForm("target");
	RobotomyRequestForm		robotomyRequestForm("target");
	PresidentialPardonForm	presidentialPardonForm("target");

	std::cout << Bureaucrat01 << std::endl;
	std::cout << Bureaucrat02 << std::endl;
	std::cout << shrubberyCreationForm << std::endl;
	std::cout << robotomyRequestForm << std::endl;
	std::cout << presidentialPardonForm << std::endl;

	Bureaucrat01.signForm(shrubberyCreationForm);
	Bureaucrat01.signForm(presidentialPardonForm);
	Bureaucrat02.signForm(shrubberyCreationForm);
	Bureaucrat02.signForm(presidentialPardonForm);

	Bureaucrat01.executeForm(shrubberyCreationForm);
	Bureaucrat01.executeForm(robotomyRequestForm);
	Bureaucrat01.executeForm(presidentialPardonForm);
	Bureaucrat02.executeForm(shrubberyCreationForm);
	Bureaucrat02.executeForm(robotomyRequestForm);
	Bureaucrat02.executeForm(presidentialPardonForm);

	return (0);
}