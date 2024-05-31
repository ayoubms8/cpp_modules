#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Aform.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();
		Intern	&operator=(Intern const &copy);

		Aform	*makeForm(std::string const &name, std::string const &target) const;
};

#endif