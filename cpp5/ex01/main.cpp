#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		Form f1;
		Bureaucrat b2("b2", 150);


		std::cout << f1 << std::endl;
		std::cout << b2 << std::endl;
		f1.beSigned(b2);
		std::cout << f1 << std::endl;
	}
	{
		Bureaucrat b2("b2", 150);
		Form f1( "f1", 12, 15);


		std::cout << f1 << std::endl;
		std::cout << b2 << std::endl;

		b2.signForm(f1);
	}
	{
		try
		{;
			Form f1("42Form", 42, 42);
			Bureaucrat b2("b2", 150);

			std::cout << f1 << std::endl;
			std::cout << b2 << std::endl;
			f1.beSigned(b2);

		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}