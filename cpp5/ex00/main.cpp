#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat("Bureaucrat", 1);
	std::cout << bureaucrat << std::endl;
	try
	{
		bureaucrat.incrementGrade();
		bureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;
	try
	{
		bureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;
	try
	{
		Bureaucrat bureaucrat2("Bureaucrat2", 0);
		std::cout << bureaucrat2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat3("Bureaucrat3", 151);
		std::cout << bureaucrat3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}