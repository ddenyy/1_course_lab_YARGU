#pragma once
#include "Header.h"

#include "Point.h"


class Line
{
public:
	double A, B, C;

	// конструктор линии по двум точкам
	Line(Point p1, Point p2)
	{
		A = p2.y - p1.y;
		B = p1.x - p2.x;
		C = -p1.x * p2.y + p2.x * p1.y;
	}

	// констуктор линии по общему ур-нию прямой
	Line(double A, double B, double C) {
		this->A = A;
		this->B = B;
		this->C = C;
	}

	// констуктор линии по точке и углу наклона
	Line(double coefficient, Point p1)
	{
		Point p2;
		double shift;
		shift = p1.y - p1.x * coefficient;

		if (p1.x != -1)
		{
			p2.x = p1.x + 1;
		}
		else {
			p2.x = p1.x - 1;
		}

		p2.y = coefficient * p2.x + shift;

		A = p2.y - p1.y;
		B = p1.x - p2.x;
		C = -p1.x * p2.y + p2.x * p1.y;
	}

	bool operator == (Line a)
	{
		if (abs(this->A - a.A) < EPS && abs(this->B - a.B) < EPS && abs(this->C - a.C) < EPS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (Line a)
	{
		return !(a == *this);
	}

};