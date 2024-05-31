#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *inventory[4];
public:
	Character(std::string const &name);
	Character();
	Character(Character const &copy);
	Character &operator=(Character const &copy);
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	~Character();
};

Character::Character(/* args */)
{
}

Character::~Character()
{
}


#endif