#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(5);

	std::list<int> lst;
	lst.push_back(6);
	lst.push_back(7);
	lst.push_back(8);
	lst.push_back(9);
	lst.push_back(18);

	try {
        std::cout << easyfind(vec, 3) << " Found" << " in vector.\n";
    } catch (std::exception) {
        std::cout << "Did not find 3 in vector.\n";
    }

    try {
        std::cout << easyfind(lst, 18) << " Found" << " in list.\n";
    } catch (std::exception) {
        std::cout << "Did not find 10 in list.\n";
	}
	return 0;
}
