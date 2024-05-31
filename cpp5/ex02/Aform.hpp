#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Aform
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public:
		Aform();
		Aform(std::string const &name, int gradeToSign, int gradeToExecute);
		Aform(Aform const &copy);
		Aform &operator=(Aform const &copy);
		virtual ~Aform();

		std::string const	&getName() const;
		bool const			&getSigned() const;
		int	const			&getGradeToSign() const;
		int	const			&getGradeToExecute() const;
		void				beSigned(Bureaucrat const &bureaucrat);

		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Aform const &form);

#endif