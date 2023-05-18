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
	//virtual bool isCongruentTo(const Shape& another);

	//// подобна ли эта фигура в геометрическом смысле
	//virtual bool isSimilarTo(const Shape& another);

	//// содержит ли фигура точку
	//virtual bool containsPoint(Point point);


	//virtual void rotate(Point center, double angle);

	//// симметрия относительно линии
	//virtual void reflex(Line axis);

	//// симметрия относительно точки
	//virtual void reflex(Point center);

	//virtual void scale(Point center, double coef);
};