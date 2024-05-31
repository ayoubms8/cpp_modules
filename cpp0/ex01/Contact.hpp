#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class contact
{
private:
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string nickname;
	std::string	email_address;
	std::string	phone_number;
	std::string darkest_secret;
public:
	contact();
	~contact();
	void	set_index(int index);
	void	set_first_name(std::string first_name);
	void	set_last_name(std::string last_name);
	void	set_nickname(std::string nickname);
	void	set_email_address(std::string email_address);
	void	set_phone_number(std::string phone_number);
	void	set_darkest_secret(std::string darkest_secret);
	int			get_index();
	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nickname();
	std::string	get_email_address();
	std::string	get_phone_number();
	std::string	get_darkest_secret();
};

#endif