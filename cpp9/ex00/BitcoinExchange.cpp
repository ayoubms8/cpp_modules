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
		//nothing
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void get_date(int *year, int *month, int *day, std::string str)
{
	std::string::size_type pos, pos2;

	pos = str.find('-');
    if (pos != std::string::npos) {
        *year = atoi(str.substr(0, pos).c_str());
		pos2 = str.find('-', pos + 1);
		if (pos2 != std::string::npos)
		{
			*month = atoi(str.substr(pos + 1, pos2).c_str());
			*day = atoi(str.substr(pos2 + 1).c_str());
		}
		else
			std::cerr << "bad input" << std::endl;
    }
	else
		std::cerr << "bad input" << std::endl;
}

int	valid_date(int year, int month, int day)
{
	if (year )
	if (month > 12 || month < 1 || day > 31 || day < 1)
		return 0;
	if (month == 2 && day > 29)
		return 0;
	if (year % 4 != 0 && month == 2 && day >= 29)
		return 0;
	return 1;
}

int BitcoinExchange::exchange(std::string &key, std::string &value, std::map<std::string, std::string> &data, double *res)
{
	int year, month, day;
	int year2, month2, day2;
	double val, val2;

	get_date(&year2, &month2, &day2, key);
	val2 = atof(value.c_str());
	if (val2 < 0 || val2 >= 1000 || !valid_date(year2, month2, day2))
	{
		if (!valid_date(year2, month2, day2))
			std::cerr << "Error: invalid date" << std::endl;
		else if (val2 >= 1000)
			std::cerr << "Error: too large a number" << std::endl;
		else
			std::cerr << "Error: not a positive number." << std::endl;
		return 0;
	}
	
	std::map<std::string, std::string>::iterator it;
	for(it = data.end(); it != data.begin(); it--) {
   		get_date(&year, &month, &day, it->first);
		val = atof(it->second.c_str());
		if (val )
		if (year2 == year)
		{
			if (month2 == month)
			{
				if (day2 >= day)
				{
					*res = val * val2;
					return (1);
				}
			}
		}
	}
	return (0);
}