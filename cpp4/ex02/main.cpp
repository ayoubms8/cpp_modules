#include "Dog.hpp"
#include "Cat.hpp"

void leaks()
{
	system("leaks Animal");
}

int main()
{
	atexit(leaks);
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	delete j;
	delete i;
	return 0;
}