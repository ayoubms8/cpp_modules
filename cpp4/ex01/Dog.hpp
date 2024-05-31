#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
	Dog();
	Dog(Dog const &copy);
	Dog &operator=(Dog const &copy);
	void makeSound(void) const;
	~Dog();
};

#endif