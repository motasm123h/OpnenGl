#include "Point.h"

Point::Point(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
}
Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0;
}

Point::Point(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}