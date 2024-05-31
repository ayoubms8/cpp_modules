#include "Array.hpp"
#include <iostream>

int main()
{
	try
	{
		Array<int> intArray(10);
		for (int i = 0; i < 10; i++)
			intArray[i] = i + 5;
		for (int i = 0; i < 10; i++)
			std::cout << "intArray[" << i << "] " << intArray[i] << std::endl;
		std::cout << "Size of intArray: " << intArray.size() << std::endl;

		Array<double> doubleArray(5);
		for (int i = 0; i < 5; i++)
			doubleArray[i] = i + 0.2;
		for (int i = 0; i < 5; i++)
			std::cout << "doubleArray[" << i << "] " << doubleArray[i] << std::endl;
		std::cout << "Size of doubleArray: " << doubleArray.size() << std::endl;

		Array<std::string> stringArray;
		std::cout << "Size of stringArray: " << stringArray.size() << std::endl;
	}
	catch (std::exception())
	{
		std::cout << "exception caught!!" << std::endl;
	}
	return 0;
}