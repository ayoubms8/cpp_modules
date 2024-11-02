#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	if (this != &copy)
	{
		// nothing
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void get_date(int *year, int *month, int *day, std::string str)
{
	if (str.size() != 10 || str[4] != '-' || str[7] != '-')
		return;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (i != 4 && i != 7 && !std::isdigit(str.at(i)))
			return;
	}

	std::string::size_type pos, pos2;

	pos = str.find('-');
	if (pos != std::string::npos)
	{
		*year = atoi(str.substr(0, pos).c_str());
		pos2 = str.find('-', pos + 1);
		if (pos2 != std::string::npos)
		{
			*month = atoi(str.substr(pos + 1, pos2).c_str());
			*day = atoi(str.substr(pos2 + 1).c_str());
		}
		else
			std::cout << "bad input" << std::endl;
	}
	else
		std::cout << "bad input" << std::endl;
}

bool valid_date(int year, int month, int day)
{
	if (month > 12 || month < 1 || day > 31 || day < 1)
		return 0;
	if (month == 2 && day > 29)
		return 0;
	if (year % 4 != 0 && month == 2 && day >= 29)
		return 0;
	return 1;
}

bool is_valid_float(const std::string &s)
{
	std::stringstream ss(s);
	float f;
	if (!(ss >> f))
        return false;
    if (!ss.eof())
        ss >> std::ws;
    return (ss.eof() && !ss.fail());
}

int BitcoinExchange::exchange(std::string &key, std::string &value, std::map<std::string, std::string> &data, double *res)
{
	int year, month, day;
	int k_year, k_month, k_day;
	double val, val2;

	get_date(&k_year, &k_month, &k_day, key);
	if (!is_valid_float(value))
		return (std::cout << "Error: invalid number" << std::endl, 0);
	val2 = atof(value.c_str());
	if (val2 < 0 || val2 > 1000 || !valid_date(k_year, k_month, k_day))
	{
		if (!valid_date(k_year, k_month, k_day))
			std::cout << "Error: invalid date" << std::endl;
		else if (val2 > 1000)
			std::cout << "Error: too large a number" << std::endl;
		else
			std::cout << "Error: not a positive number." << std::endl;
		return 0;
	}

	std::map<std::string, std::string>::iterator it;
	for (it = data.end(); true;)
	{
		it--;
		get_date(&year, &month, &day, it->first);
		val = atof(it->second.c_str());
		if ((k_year == year && k_month == month && k_day >= day) \
		 	|| (k_year == year && k_month > month) || k_year > year) 
			return (*res = val * val2, 1);
		if (it == data.begin())
			return (*res = val * val2, 1);
	}
	return (0);
}