#include "Phonebook.hpp"
#include <iostream>

int	main(void)
{
	std::string option;
	phonebook	phbook;

	while (1)
	{
		while(option != "ADD" && option != "SEARCH" && option != "EXIT")
		{
			std::cout << "Choose An Option: ADD, SEARCH, EXIT..." << std::endl;
			getline(std::cin, option);
			if (std::cin.eof() && std::cout << "end of input\nexiting..." << std::endl)
				exit(0);
		}
		if (option == "ADD")
		{
			phbook.add_contact();
		}
		else if (option == "SEARCH")
		{
			phbook.search_contact();
		}
		else if (option == "EXIT")
		{
			exit(0);
		}
		option = "";
	}
}
