#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN const &copy)
{
	*this = copy;
}

RPN &RPN::operator=(RPN const &copy)
{
	if (this != &copy)
	{
		//nothing
	}
	return (*this);
}

RPN::~RPN()
{
}

int RPN::calculate(std::stack<int> *stak, int *res, std::string str)
{
	int a;
	int b;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str.at(i)))
			stak->push(str.at(i) - '0');
		else if (str.at(i) == '-' || str.at(i) == '+' \
		|| str.at(i) == '*' || str.at(i) == '/')
		{
			if (stak->size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return 0;
			}
			b = stak->top();
			stak->pop();
			a = stak->top();
			stak->pop();
			if (str.at(i) == '*')
				stak->push(a * b);
			else if (str.at(i) == '+')
				stak->push(a + b);
			else if (str.at(i) == '-')
				stak->push(a - b);
			else if (str.at(i) == '/')
				stak->push(a / b);
		}
		else if (str.at(i) != ' ')
		{
			std::cerr << "Error" << std::endl;
			return 0;
		}
	}
	if (stak->size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return 0;
	}
	*res = stak->top();
	return 1;
}