#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include "Contact.hpp"

class phonebook
{
private:
	contact	contacts[8];
public:
	phonebook();
	~phonebook();
	void	add_contact();
	void	search_contact();
};
#endif