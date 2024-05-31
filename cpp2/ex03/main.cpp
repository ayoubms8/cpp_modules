#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);
	if (bsp(a, b ,c, Point(2.49, 2.5)))
	{
		std::cout << "inside" << std::endl;
	}
	else
		std::cout << "outside" << std::endl;
}