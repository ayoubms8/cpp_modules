#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include "Aform.hpp"

class RobotomyRequestForm : public Aform
{
	private:
		std::string const	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
		~RobotomyRequestForm();

		std::string const	&getTarget() const;
		void		execute(Bureaucrat const &executor) const;
};

#endif