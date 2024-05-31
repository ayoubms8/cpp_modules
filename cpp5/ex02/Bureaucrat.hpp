#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Aform;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		Bureaucrat();
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &copy);
		~Bureaucrat();

		std::string const	&getName() const;
		int	const			&getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Aform &form) const;
		void				executeForm(Aform const &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif