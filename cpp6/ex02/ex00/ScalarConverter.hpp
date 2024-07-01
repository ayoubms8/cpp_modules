#pragma once
#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &copy);
	ScalarConverter &operator=(ScalarConverter const &copy);
	~ScalarConverter();
public:
	static void convert(std::string &str);
};
