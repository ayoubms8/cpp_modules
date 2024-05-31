#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Aform.hpp"

class ShrubberyCreationForm : public Aform
{
	private:
		std::string const	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm();

		std::string const	&getTarget() const;
		void		execute(Bureaucrat const &executor) const;
};

#endif