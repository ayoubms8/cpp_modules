#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Aform.hpp"

class PresidentialPardonForm : public Aform
{
	private:
		std::string const	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
		~PresidentialPardonForm();

		std::string const	&getTarget() const;
		void		execute(Bureaucrat const &executor) const;
};

#endif