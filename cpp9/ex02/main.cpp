#include "PmergeMe.hpp"

template<typename T>
void	parse(char **av, T&container, int &num)
{
	int num1;
	bool even = 1;
	for (int  i = 1; av[i]; i++) {
		even = 0;
		num = atoi(av[i]);
		if (av[i + 1])
		{
			i++;
			num1 = atoi(av[i]);
			container.push_back(std::make_pair(num, num1));
			even = 1;
		}
		else
			break;
	}
	if (even)
		num = -1;
}

int main(int ac, char **av)
{
	if (ac <= 2)
	{
		std::cerr << "Wrong number of arguments!" << std::endl;
		return 0;
	}
	int i = 1;
	int j = 0;
	while (av[i])
	{
		if (!strcmp(av[i], ""))
			return (std::cerr << "Error" << std::endl, 1);
		j = 0;
		while (av[i][j])
		{
			if (!std::isdigit(av[i][j]) && av[i][0] != '+')
        		return (std::cerr << "Error" << std::endl, 1);
			if (av[i][0] == '+' && !av[i][1])
				return (std::cerr << "Error" << std::endl, 1);
			j++;
		}
		i++;
	}
	
	std::vector<int> main_vec;
	std::deque<int> main_que;

	std::vector<std::pair<int, int> > vec;
	std::deque<std::pair<int, int> > que;

	int num ;
	parse(av, vec, num);
	parse(av, que, num);
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i].first << " " << vec[i].second << " ";
	}
	if (num != -1)
			std::cout << num;
	std::cout << std::endl;

	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;
	std::chrono::duration<double, std::micro> elapsed;

	start = std::chrono::high_resolution_clock::now();
	if(!PmergeMe::FordJohnson(num, main_vec, vec))
    	return 1;
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;

	std::cout << "After: ";
	for (size_t i = 0; i < main_vec.size(); i++)
	{
		std::cout << main_vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << main_vec.size() << " elements with std::vector: " << elapsed.count() << " us" << std::endl;
	start = std::chrono::high_resolution_clock::now();
	if(!PmergeMe::FordJohnson(num, main_que, que))
		return 1;
	end = std::chrono::high_resolution_clock::now();
	elapsed = end - start;
	std::cout << "Time to process a range of " << main_que.size() << " elements with std::deque: " << elapsed.count() << " us" << std::endl;
}
