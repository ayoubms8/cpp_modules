#include "Iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void add(T &a)
{
	a += a;
}

int main()
{
	std::string arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = "str"+ std::to_string(i);

	std::cout << "-----------BEFORE----------" << std::endl;
	for(int i = 0; i < 10; i++)
		std::cout << arr[i] << std::endl;
	
	Iter(arr, 10, add<std::string>);
	Iter(arr, 10, add);

	std::cout << "-----------AFTER----------" << std::endl;
	for(int i = 0; i < 10; i++)
		std::cout << arr[i] << std::endl;
}