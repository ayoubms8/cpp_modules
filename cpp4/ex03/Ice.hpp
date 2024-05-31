#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	/* data */
public:
	Ice(/* args */);
	~Ice();
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif