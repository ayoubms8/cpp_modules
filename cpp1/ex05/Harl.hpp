#ifndef HARL_HPP
# define HARL_HPP
# include <string.h>
# include <iostream>

class Harl
{
private:
	void	debug(void);
	void	warning(void);
	void	info(void);
	void	error(void);
public:
    typedef void (Harl::*LevelFunction)();
	void complain( std::string level );
	Harl();
	~Harl();
};


#endif