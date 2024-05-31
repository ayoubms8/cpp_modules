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
	Fixed operator+(Fixed const &copy) const;
	Fixed operator-(Fixed const &copy) const;
	Fixed operator*(Fixed const &copy) const;
	Fixed operator/(Fixed const &copy) const;
	bool operator<(Fixed const &copy) const;
	bool operator<=(Fixed const &copy) const;
	bool operator>=(Fixed const &copy) const;
	bool operator>(Fixed const &copy) const;
	bool operator==(Fixed const &copy) const;
	bool operator!=(Fixed const &copy) const;
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed const &max(Fixed const &a, Fixed const &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	~Fixed();
};

std::ostream &operator<<(std::ostream &out, Fixed const &_fixed);

#endif