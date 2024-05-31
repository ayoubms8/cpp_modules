#include "Aform.hpp"

Aform::Aform() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Aform::Aform(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Aform::GradeTooLowException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Aform::GradeTooHighException();
}

Aform::Aform(Aform const &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Aform::~Aform()
{
}

Aform &Aform::operator=(Aform const &copy)
{
	_signed = copy._signed;
	return (*this);
}

std::string const &Aform::getName() const
{
	return (_name);
}

bool const &Aform::getSigned() const
{
	return (_signed);
}

int const &Aform::getGradeToSign() const
{
	return (_gradeToSign);
}

int const &Aform::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Aform::beSigned(Bureaucrat const &bureaucrat)
{
	if (_signed)
	{
		std::cout << bureaucrat.getName() << " cannot sign " << _name << " because it is already signed" << std::endl;
		return;
	}
	_signed = true;
	std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
}

const char *Aform::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Aform::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *Aform::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, Aform const &form)
{
	out << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ", form signed " << form.getSigned();
	return (out);
}