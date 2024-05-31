#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	/* data */
public:
	MateriaSource(/* args */);
	~MateriaSource();
	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

MateriaSource::MateriaSource(/* args */)
{
}

MateriaSource::~MateriaSource()
{
}


#endif