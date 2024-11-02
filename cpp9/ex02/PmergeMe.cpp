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

template<typename T>
void merge(T& container, int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    T L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = container[low + i];
    for (j = 0; j < n2; j++)
        R[j] = container[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            container[k] = L[i];
            i++;
        }
        else {
            container[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        container[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        container[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
void PmergeMe::mergeSort(T& container, int low, int high) {
    if (low < high) {
        int mid = (high + low) / 2;

        mergeSort(container, low, mid);
        mergeSort(container, mid + 1, high);

        merge(container, low, mid, high);
    }
}

int	jacobsthal(int a)
{
	if (a <= 0)
		return 0;
	else if (a == 1)
		return 1;
	else
		return (jacobsthal(a - 1) + (2 * jacobsthal(a - 2)));
}

int PmergeMe::FordJohnson(int num, std::vector<int> &main, std::vector<std::pair<int, int> > &vec)
{
	for (std::vector<std::pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
	mergeSort(vec, 0, vec.size() - 1);
	int comb[vec.size() * 2];

	unsigned int k = 0;
	for (size_t i = 2; k < vec.size() * 2; i++)
	{
    	comb[k++] = jacobsthal(i);
    	if (i != 0) {
    	    int temp = jacobsthal(i) - 1;
    	    while (temp > jacobsthal(i - 1) && (k < vec.size() * 2)) {
    	        comb[k++] = temp--;
    	    }
    	}
	}

	std::vector<int> pend;
	main.push_back(vec.at(0).second);
	for (size_t i = 0; i < vec.size(); i++)
	{
		main.push_back(vec.at(i).first);
		pend.push_back(vec.at(i).second);
	}
	std::vector<int>::iterator it;
	size_t j = 0;

	for (size_t i = 0; j < pend.size() - 1; i++)
	{
		if (static_cast<unsigned long>(comb[i]) < pend.size())
		{
			it = std::lower_bound(main.begin(), main.end(), pend[comb[i]]);
			main.insert(it, pend[comb[i]]);
			j++;
		}
	}
	if (num != -1)
	{
		it = std::lower_bound(main.begin(), main.end(), num);
		main.insert(it, num);
	}
	return 1;
}

int PmergeMe::FordJohnson(int num, std::deque<int> &main, std::deque<std::pair<int, int> > &deq)
{
	for (std::deque<std::pair<int, int> >::iterator it = deq.begin(); it != deq.end(); it++)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
	mergeSort(deq, 0, deq.size() - 1);
	int comb[deq.size() * 2];

	unsigned int k = 0;
	for (size_t i = 2; i < deq.size() && (k < deq.size() * 2); i++)
	{
    	comb[k++] = jacobsthal(i);
    	if (i != 0) {
    	    int temp = jacobsthal(i) - 1;
    	    while (temp > jacobsthal(i - 1) && (k < deq.size() * 2)) {
    	        comb[k++] = temp--;
    	    }
    	}
	}

	std::deque<int> pend;
	main.push_back(deq.at(0).second);
	for (size_t i = 0; i < deq.size(); i++)
	{
		main.push_back(deq.at(i).first);
		pend.push_back(deq.at(i).second);
	}
	std::deque<int>::iterator it;
	size_t j = 0;

	for (size_t i = 0; j < pend.size() - 1; i++)
	{
		if (static_cast<unsigned long>(comb[i]) < pend.size())
		{
			it = std::lower_bound(main.begin(), main.end(), pend[comb[i]]);
			main.insert(it, pend[comb[i]]);
			j++;
		}
	}
	if (num != -1)
	{
		it = std::lower_bound(main.begin(), main.end(), num);
		main.insert(it, num);
	}
	return 1;
}
