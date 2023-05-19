#pragma once
#include "Header.h"

#include "Point.h"


class Line
{
public:
	double A, B, C;

	// ����������� ����� �� ���� ������
	Line(Point p1, Point p2)
	{
		A = p2.y - p1.y;
		B = p1.x - p2.x;
		C = -p1.x * p2.y + p2.x * p1.y;
	}

	// ���������� ����� �� ������ ��-��� ������
	Line(double A, double B, double C) {
		this->A = A;
		this->B = B;
		this->C = C;
	}

	// ���������� ����� �� ����� � ���� �������
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

	// �-��� ������ ������������� ������ �� ������ ���� � ����������
	/*
	Ax+By+C = 0 ==> r = at+b
	*/
	pair<Point, Point> transform_equation_line()
	{
		// ����� - ��� �� �������
		Point a, b;
		if (abs(this->A) < EPS) {
			a = Point(0, -this->C / this->B);
			b = Point(1, -this->C / this->B);
		} 
		else
		{
			a = Point(-this->C / this->A, 0);
			b = Point(-(this->C + this->B) / A, 1);
		}
		pair<Point, Point> ans;
		ans.first = a;
		ans.second = b;

		return ans;
	} 

};