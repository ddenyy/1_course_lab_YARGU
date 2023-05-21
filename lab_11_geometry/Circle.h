#pragma once
#include "Header.h"
#include "Polygon.h"
#include "Ellipse.h"

class Circle: public Ellipse
{
public:
	Circle(Point center, double radius) : Ellipse(center, center, radius)
	{
		this->center = center;
		this->radius = radius;
	}
	
	double getRadius()
	{
		return this->radius;
	}

	// равенство двух окружностей
	bool isCongruentTo(Circle& another)
	{
		if (abs(this->radius - another.radius) < EPS)
		{
			return true;
		}
		return false;
	}

	bool isSimilarTo(Circle& another)
	{
		return true;
	}

	bool operator == (Circle& another)
	{
		if (this->isCongruentTo(another))
		{
			return true;
		}
		return false;
	}
private:
	Point center;
	double radius;

};

