#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Error: could not open file." << std::endl, 1);
	std::ifstream database;
	std::ifstream input;
	database.open("data.csv");
	if (!database)
		return (std::cout << "Error: could not open database file." << std::endl, 1);
	input.open(av[1]);
	if (!input)
		return (std::cout << "Error: could not open file." << std::endl, 1);
	std::map<std::string, std::string> data;
	std::string line, key, value;
	int i = 0;
	while (std::getline(database, line))
	{
		std::string::size_type pos = line.find(',');
		if (pos != std::string::npos)
		{
			key = line.substr(0, pos);
			value = line.substr(pos + 1);
			if ((strcmp(key.c_str(), "date") || strcmp(value.c_str(), "exchange_rate")) && !i)
				return (std::cerr << "Error: bad format" << std::endl, 1);
			else if (!i && ++i)
				continue;
			data[key] = value;
		}
	}
	double res;
	i = 0;
	while (std::getline(input, line))
	{
		std::string::size_type pos = line.find(" | ");
		if (pos != std::string::npos)
		{
			key = line.substr(0, pos);
			value = line.substr(pos + 3);
			if ((strcmp(key.c_str(), "date") || strcmp(value.c_str(), "value")) && !i)
				return (std::cerr << "Error: bad format" << std::endl, 1);
			else if (!i && ++i)
				continue;
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (BitcoinExchange::exchange(key, value, data, &res))
		{
			value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
			std::cout << key << " => " << value << " = " << res << std::endl;
		}
	}
}