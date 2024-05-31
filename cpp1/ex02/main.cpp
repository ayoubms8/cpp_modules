#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	std::cout << "the memory address of str: " << &str << std::endl;
	std::cout << "the memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "the memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "the value of str: " << str << std::endl;
	std::cout << "the value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "the value pointed to by stringREF: " << stringREF << std::endl;
}