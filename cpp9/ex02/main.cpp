#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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
	std::vector<std::pair<int, int>> vec;
	
	std::stringstream ss(str);
	int num, num1;
	while (ss >> num >> num1) {
		vec.push_back(std::make_pair(num, num1));
	}
	// int struggler;
	// if (vec.size() % 2)
	// 	struggler = vec.at(vec.size() - 1);
	
}
