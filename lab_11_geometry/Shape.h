#pragma once
#include "Header.h"
#include "Point.h"
#include "Line.h"


class Shape
{

public:
	double perimetr();

	double area();

	// ��������� �� ������ � ������
	bool operator == (Shape& another);

	//// ����� �� ��� ������ � �������������� ������
	//virtual bool isCongruentTo(const Shape& another);

	//// ������� �� ��� ������ � �������������� ������
	//virtual bool isSimilarTo(const Shape& another);

	//// �������� �� ������ �����
	//virtual bool containsPoint(Point point);


	//virtual void rotate(Point center, double angle);

	//// ��������� ������������ �����
	//virtual void reflex(Line axis);

	//// ��������� ������������ �����
	//virtual void reflex(Point center);

	//virtual void scale(Point center, double coef);
};