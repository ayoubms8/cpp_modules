#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <iostream>

class Weapon
{
private:
	std::string type;
public:
	void setType(std::string type);
	const std::string getType(void);
	Weapon(std::string type);
	~Weapon();
};

#endif