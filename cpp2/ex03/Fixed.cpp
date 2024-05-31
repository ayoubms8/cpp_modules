#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int value)
{
	_value = (value << _bits);
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (float)(1 << _bits));
}

int Fixed::toInt(void) const
{
	return (_value >> _bits);
}

float Fixed::toFloat() const
{
	return ((float)_value / (float)(1 << _bits));
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
	if (this != &copy)
		this->_value = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

bool Fixed::operator!=(Fixed const &copy) const
{
	return (this->_value != copy._value);
}

bool Fixed::operator==(Fixed const &copy) const
{
	return (this->_value == copy._value);
}

bool Fixed::operator<=(Fixed const &copy) const
{
	return (this->_value <= copy._value);
}

bool Fixed::operator>=(Fixed const &copy) const
{
	return (this->_value >= copy._value);
}

bool Fixed::operator<(Fixed const &copy) const
{
	return (this->_value < copy._value);
}

bool Fixed::operator>(Fixed const &copy) const
{
	return (this->_value > copy._value);
}

Fixed &Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(this->toFloat());
	_value++;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(this->toFloat());
	_value--;
	return (temp);
}

Fixed Fixed::operator+(Fixed const &copy) const
{
	return(Fixed(this->toFloat() + copy.toFloat()));
}

Fixed Fixed::operator-(Fixed const &copy) const
{
	return(Fixed(this->toFloat() - copy.toFloat()));
}

Fixed Fixed::operator*(Fixed const &copy) const
{
	return(Fixed(this->toFloat() * copy.toFloat()));
}

Fixed Fixed::operator/(Fixed const &copy) const
{
	return(Fixed(this->toFloat() / copy.toFloat()));
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed::~Fixed()
{
}

std::ostream &operator<<(std::ostream &out, Fixed const &_fixed)
{
	out << _fixed.toFloat();
	return out;
}