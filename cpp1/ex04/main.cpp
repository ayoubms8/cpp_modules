#include <string>
#include <iostream>
#include <fstream>

std::string	replace_strings(std::string& line, std::string s1, std::string s2)
{
	std::string	replaced_line;
	int	pos = 0;
	int	nextpos = line.find(s1);
	while (nextpos != std::string::npos)
	{
		replaced_line += line.substr(pos, nextpos - pos);
		replaced_line += s2;
		pos = nextpos + s1.length();
		nextpos = line.find(s1, pos);
	}
	replaced_line += line.substr(pos);
	return (replaced_line);
}

int main(int ac, char **av)
{
	std::string	line;
	std::string	replaced_line;
	if (ac != 4)
		return (std::cout << "wrong number of args" << std::endl, 1);
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	if (!strcmp(av[2], ""))
		return (std::cout << "invalid arguments" << std::endl, 1);
	std::ifstream inputstream(filename);
	if (!inputstream)
		return (std::cerr << "invalid filename" << std::endl, 1);
	std::ofstream outputstream(filename+ ".replace");
	if (!outputstream)
		return (std::cerr << "Failed during output" << std::endl, 1);
	while(std::getline(inputstream, line))
	{
		replaced_line = replace_strings(line, s1, s2);
		outputstream << replaced_line << std::endl;
	}
}