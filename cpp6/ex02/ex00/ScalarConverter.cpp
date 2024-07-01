#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
	if (this != &copy)
	{
		//nothing
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

int mixedchars(const char *s)
{
	int i = 0;
	if ((s[i] == '-' || s[i] == '+' || std::isdigit(s[i])) && (strcmp(s, "nan") \
		&& strcmp(s, "inf") && strcmp(s, "-inf")))
	{
		i++;
		while (s[i] && std::isdigit(s[i]))
			i++;
		if (s[i] && s[i] != '.' && s[i] != 'f')
			return (1);
		i++;
		while (s[i] && std::isdigit(s[i]))
			i++;
		if (s[i] && (s[i] != 'f' || s[i + 1]))
			return(1);
	}
	return (0);
}

void ScalarConverter::convert(std::string &s)
{
	char    c;
	int     i; 
	float   f;
	double  d;
	const char	*str = s.c_str();

	if (mixedchars(str))
		f = d = i = c = 0;
	else if (s.length() == 1 && !std::isdigit(s.at(0)) && (strcmp(str, "nan") \
		&& strcmp(str, "inf") && strcmp(str, "-inf")))
		f = d = i = c = s.at(0);
	else
	{
		c = static_cast<char>(atoi(str));
		i = atoi(str);
		d = atof(str);
		f = static_cast<float>(d);
	}
	std::cout << "char: ";
	if (std::isprint(i))
		std::cout << "'" << c << "'" << std::endl;
	else if (d == std::numeric_limits<double>::quiet_NaN() || std::abs(d) == std::numeric_limits<double>::infinity())
		std::cout << "impossible" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (i == 0 && strcmp(str, "0"))
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
	std::cout << "float: ";
	if (f == 0 && strcmp(str, "0"))
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" <<std::endl;
	std::cout << "double: ";
	if (d == 0 && strcmp(str, "0"))
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << d << std::endl;
}