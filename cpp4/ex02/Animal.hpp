#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(Animal const &copy);
	Animal &operator=(Animal const &copy);
	void virtual makeSound(void) const = 0;
	std::string getType(void) const;
	virtual ~Animal();
};


#endif