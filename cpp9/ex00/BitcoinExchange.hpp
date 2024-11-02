#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &copy);
		~BitcoinExchange();
	public:
		static int exchange(std::string &key, std::string &value, std::map<std::string, std::string> &data, double *res);
};