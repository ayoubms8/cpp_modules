#include "Contact.hpp"
#include <iostream>
#include <iomanip>

contact::contact()
{
}

contact::~contact()
{
}

void	contact::set_index(int index)
{
	this->index = index;
}

void	contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void	contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void	contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void	contact::set_email_address(std::string email_address)
{
	this->email_address = email_address;
}

void	contact::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}

void	contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

int			contact::get_index()
{
	return (this->index);
}

std::string	contact::get_first_name()
{
	return (this->first_name);
}

std::string	contact::get_last_name()
{
	return (this->last_name);
}

std::string	contact::get_nickname()
{
	return (this->nickname);
}

std::string	contact::get_email_address()
{
	return (this->email_address);
}

std::string	contact::get_phone_number()
{
	return (this->phone_number);
}

std::string	contact::get_darkest_secret()
{
	return (this->darkest_secret);
}
