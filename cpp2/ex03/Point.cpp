#include "Point.hpp"

Point::Point() :_x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(const float x, const float y) :_x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Point &copy): _x(copy._x), _y(copy._y)
{
	*this = copy;
}

Point &Point::operator=(const Point &copy)
{
	return (*this);
}

Fixed Point::getX() const
{
	return(_x);
}

Fixed Point::getY() const
{
	return(_y);
}

Point::~Point()
{
}