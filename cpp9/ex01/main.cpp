#include "RPN.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments!" << std::endl;
		return 0;
	}
	if (!av[1][0])
		return 0;
	std::string str = av[1];
	std::stack<int> stak;

	int res;
	if (RPN::calculate(&stak, &res, str))
		std::cout << "Result: " << res << std::endl;
}