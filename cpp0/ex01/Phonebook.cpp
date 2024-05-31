#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

phonebook::phonebook()
{
}

phonebook::~phonebook()
{
}

void	phonebook::add_contact()
{
	int			i;
	std::string	tmp;
	static int	latest_i;

	i = 0;
	while (i < 8)
	{
		if (i + 1 > latest_i)
		{
			std::cout << "Enter first name: ";
			getline(std::cin, tmp);
			if (std::cin.eof() && std::cout << "end of input\nexiting..." << std::endl)
				exit(0);
			this->contacts[i].set_first_name(tmp);
			std::cout << "Enter last name: ";
			getline(std::cin, tmp);
			if (std::cin.eof() && std::cout << "end of input\nexiting..." << std::endl)
				exit(0);
			this->contacts[i].set_last_name(tmp);
			std::cout << "Enter nickname: ";
			getline(std::cin, tmp);
			if (std::cin.eof() && std::cout << "end of input\nexiting..." << std::endl)
				exit(0);
			this->contacts[i].set_nickname(tmp);
			std::cout << "Enter email address: ";
			getline(std::cin, tmp);
			if (std::cin.eof() && std::cout << "end of input\nexiting..." << std::endl)
				exit(0);
			this->contacts[i].set_email_address(tmp);
			std::cout << "Enter phone number: ";
			getline(std::cin, tmp);
			if (std::cin.eof() && std::cout << "end of input\nexiting..." << std::endl)
				exit(0);
			this->contacts[i].set_phone_number(tmp);
			std::cout << "Enter darkest secret: ";
			getline(std::cin, tmp);
			if (std::cin.eof() && std::cout << "end of input\nexiting..." << std::endl)
				exit(0);
			this->contacts[i].set_darkest_secret(tmp);
			this->contacts[i].set_index(i);
			latest_i = (latest_i + 1) % 8;
			break ;
		}
		i++;
	}
}

void	phonebook::search_contact()
{
	int	i;

	i = 0;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	while (i < 8)
	{
		if (!this->contacts[i].get_first_name().empty() && !this->contacts[i].get_last_name().empty())
		{
			std::cout << std::setw(10) << this->contacts[i].get_index() << "|";
			if (this->contacts[i].get_first_name().length() > 10)
				std::cout << std::setw(10) << this->contacts[i].get_first_name().substr(0, 9) + "." << "|";
			else
				std::cout << std::setw(10) << this->contacts[i].get_first_name() << "|";
			if (this->contacts[i].get_last_name().length() > 10)
				std::cout << std::setw(10) << this->contacts[i].get_last_name().substr(0, 9) + "." << "|";
			else
				std::cout << std::setw(10) << this->contacts[i].get_last_name() << "|";
			if (this->contacts[i].get_nickname().length() > 10)
				std::cout << std::setw(10) << this->contacts[i].get_nickname().substr(0, 9) + "." << std::endl;
			else
				std::cout << std::setw(10) << this->contacts[i].get_nickname() << std::endl;
		}
		i++;
	}
	std::cout << "Enter index: ";
	std::cin >> i;
	if (std::cin.eof() && std::cout << "end of input\nexiting..." << std::endl)
		exit(0);
	std::cin.ignore(10000, '\n');
	if(std::cin.fail())
	{
		std::cout << "Invalid index." << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return ;
	}
	if (i < 0 || i > 7)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	else
	{
		std::cout << std::setw(10) << "First name" << "|";
		std::cout << std::setw(10) << "Last name" << "|";
		std::cout << std::setw(10) << "Nickname" << std::endl;
		if (this->contacts[i].get_first_name().length() > 10)
			std::cout << std::setw(10) << this->contacts[i].get_first_name().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->contacts[i].get_first_name() << "|";
		if (this->contacts[i].get_last_name().length() > 10)
			std::cout << std::setw(10) << this->contacts[i].get_last_name().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->contacts[i].get_last_name() << "|";
		if (this->contacts[i].get_nickname().length() > 10)
			std::cout << std::setw(10) << this->contacts[i].get_nickname().substr(0, 9) + "." << std::endl;
		else
			std::cout << std::setw(10) << this->contacts[i].get_nickname() << std::endl;
	}
}