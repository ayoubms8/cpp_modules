#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments!" << std::endl;
		return 1;
	}
	if (!av[1][0])
		return 1;
	std::string str = av[1];
	std::stack<int> stak;

	int res;
	try
	{
		if (RPN::calculate(&stak, &res, str))
			std::cout << "Result: " << res << std::endl;
		else
			return 1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}