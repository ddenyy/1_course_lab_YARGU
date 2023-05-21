#pragma once
#include "Header.h"
#include "Point.h"
#include "Line.h"


class Shape
{

public:
	double perimetr();

	double area();

	// совпадает ли фигура с данной
	bool operator == (Shape& another);

	//// равна ли эта фигура в геометрическом смысле
	 bool isCongruentTo(const Shape& another);

	//// подобна ли эта фигура в геометрическом смысле
	 bool isSimilarTo(const Shape& another);

	//// содержит ли фигура точку
	 bool containsPoint(Point point);


	 void rotate(Point center, double angle);

	//// симметрия относительно линии
	 void reflex(Line axis);

	//// симметрия относительно точки
	 void reflex(Point center);

	 void scale(Point center, double coef);
};