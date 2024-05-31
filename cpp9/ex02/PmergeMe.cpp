#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy)
{
	if (this != &copy)
	{
		//nothing
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}
