#pragma once
#include "Header.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"

class Rectangle: public Polygon
{
public:
	using Polygon::Polygon; // подключаем конструктор базового класса

	Rectangle(Point bottom_left, Point top_right) : Polygon(4, bottom_left, Point(top_right.x, bottom_left.y), top_right, Point(bottom_left.x, top_right.y)) 
	{
		this->bottom_left = bottom_left;
		this->bottom_right = Point(top_right.x, bottom_left.y);
		this->top_right = top_right;
		this->top_left = Point(bottom_left.x, top_right.y);
	};

	pair<Line, Line> getDiagonals()
	{
		Line first_diagonal(bottom_left, top_right);
		Line second_diagonal(bottom_right, top_left);

		return { first_diagonal, second_diagonal };
	}


	Point getCenter()
	{
		double center_x = (bottom_left.x + bottom_right.x) / 2;
		double center_y = (bottom_left.y + top_left.y) / 2;

		return { center_x, center_y };
	}

	Point center;
	Point bottom_left;
	Point bottom_right;
	Point top_right;
	Point top_left;

};

