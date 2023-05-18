#pragma once
#include "Header.h"



class Point {
public:
	double x;
	double y;

	Point(double x = 0, double y = 0) : x(x), y(y) {};

	bool operator == (Point a)
	{
		if (abs(this->x - a.x) < EPS && abs(this->y - a.y) < EPS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (Point a)
	{
		return !(*this == a);
	}

	Point operator + (Point B) {
		Point res;
		res.x = x + B.x;
		res.y = y + B.y;
		return res;
	}
	Point operator - (Point B) {
		Point res;
		res.x = x - B.x;
		res.y = y - B.y;
		return res;
	}
	Point operator * (double k) {
		Point res;
		res.x = x * k;
		res.y = y * k;
		return res;
	}
};
