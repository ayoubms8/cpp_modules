#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./Harlfiler <level>" << std::endl;
		return (1);
	}

	Harl harl;

	harl.harlFilter(av[1]);
	return (0);
}