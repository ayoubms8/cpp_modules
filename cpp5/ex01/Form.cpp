#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
	_name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooLowException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &copy) :
	_name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Form::~Form()
{
}

Form &Form::operator=(Form const &copy)
{
	_signed = copy._signed;
	return (*this);
}

std::string const	&Form::getName() const
{
	return (_name);
}

bool const			&Form::getSigned() const
{
	return (_signed);
}

int const			&Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int const			&Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void				Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (_signed)
	{
		std::cout << bureaucrat.getName() << " cannot sign " << _name << " because it is already signed" << std::endl;
		return ;
	}
	_signed = true;
	std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
}

const char			*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char			*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << " is " << (form.getSigned() ? "" : "not ") << "signed, grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
	return (out);
}