#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void leaks()
{
	system("leaks Animal");
}

int main()
{
	atexit(leaks);
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongAnimal *wrong_cat = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "Wrong animal: " << std::endl;
	wrong->makeSound();
	wrong_cat->makeSound();
	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrong_cat;
	return 0;
}