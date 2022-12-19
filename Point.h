#pragma once

class Point
{
public:
	float x;
	float y;
	float z;
	Point(const Point& p);
	Point(float x, float y);
	Point(float x, float y, float z);
};
