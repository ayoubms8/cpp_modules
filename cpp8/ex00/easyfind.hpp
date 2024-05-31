#pragma once
#include <exception>
#include <algorithm>

template <typename T>
int	easyfind(T &container, int i)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), i);
	if (it != container.end())
		return *it;
	throw std::exception();
}