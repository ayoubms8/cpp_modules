#include "Bureaucrat.hpp"
#include "Aform.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (this != &copy)
	{
		const_cast<std::string&>(this->_name) = copy._name;
		this->_grade = copy._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string const	&Bureaucrat::getName() const
{
	return (this->_name);
}

int	const			&Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void				Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void				Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void				Bureaucrat::signForm(Aform &form) const
{
	try
	{
		if (form.getGradeToSign() <= this->_grade)
			throw Aform::GradeTooLowException();
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because the bureaucrat's " << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm(Aform const &form) const
{
	try
	{
		if (form.getGradeToExecute() <= this->_grade)
			throw Aform::GradeTooLowException();
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because the bureaucrat's " << e.what() << std::endl;
	}
}

const char			*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char			*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}