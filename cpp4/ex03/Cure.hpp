#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	/* data */
public:
	Cure(/* args */);
	~Cure();
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif