#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Error: could not open file." << std::endl;
	std::ifstream database;
	std::ifstream input;
	database.open("data.csv");
	if (!database)
		std::cout << "Error: could not open file." << std::endl;
	input.open(av[1]);
	if (!input)
		std::cout << "Error: could not open file." << std::endl;
	std::map<std::string, std::string> data;
	std::string line, key, value;
	std::getline(database, line);
	while (std::getline(database, line))
	{
		std::string::size_type pos = line.find(',');
    	if (pos != std::string::npos) {
    	    key = line.substr(0, pos);
    	    value = line.substr(pos + 1);
    	    data[key] = value;
    	}
	}
	double res;
	//std::getline(input, line);
	while (std::getline(input, line)){
		std::string::size_type pos = line.find(" | ");
    		if (pos != std::string::npos) {
    		    key = line.substr(0, pos);
    		    value = line.substr(pos + 3);
    		}
			else
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}
		if (BitcoinExchange::exchange(key, value, data, &res))
			std::cout << key << " => " << value << " = " << res << std::endl;
	}
}