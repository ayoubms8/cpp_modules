#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	ax = a.getX().toFloat();
	float	ay = a.getY().toFloat();
	float	bx = b.getX().toFloat();
	float	by = b.getY().toFloat();
	float	cx = c.getX().toFloat();
	float	cy = c.getY().toFloat();
	float	px = point.getX().toFloat();
	float	py = point.getY().toFloat();
	float	abc = std::abs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2;
	float	abp = std::abs(ax * (by - py) + bx * (py - ay) + px * (ay - by)) / 2;
	float	acp = std::abs(ax * (py - cy) + px * (cy - ay) + cx * (ay - py)) / 2;
	float	bcp = std::abs(px * (by - cy) + bx * (cy - py) + cx * (py - by)) / 2;
	if (abp && acp && bcp && abp + acp + bcp == abc)
   		return true;
	return false;
}