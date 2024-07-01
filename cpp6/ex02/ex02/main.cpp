#include "Base.hpp"
#include "funcs.hpp"

int	main(void)
{
	int num = 10;
	Base *base[num];

	for(int i = 0; i < num; i++)
		base[i] = generate();
	std::cout << "----------------------by pointer----------------------" << std::endl;
	for(int i = 0; i < num; i++)
		identify(base[i]);
	std::cout << "---------------------by reference----------------------" << std::endl;
	for(int i = 0; i < num; i++)
		identify(*base[i]);
	for (int i = 0; i < num; i++)
		delete base[i];
}