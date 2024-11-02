#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &copy);
		~PmergeMe();
	public:
		static int FordJohnson(int num, std::vector<int> &main, std::vector<std::pair<int, int> > &vec);
		static int FordJohnson(int num, std::deque<int> &main, std::deque<std::pair<int, int> > &deq);

		template<typename T>
		static void mergeSort(T& container, int low, int high);
};
