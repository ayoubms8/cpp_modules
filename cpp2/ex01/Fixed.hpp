#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int _value;
	static const int _bits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(Fixed const &copy);
	Fixed &operator=(Fixed const &copy);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	~Fixed();
};

std::ostream &operator<<(std::ostream &out, Fixed const &_fixed);

#endif