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
	 bool isCongruentTo(const Shape& another);

	//// ������� �� ��� ������ � �������������� ������
	 bool isSimilarTo(const Shape& another);

	//// �������� �� ������ �����
	 bool containsPoint(Point point);


	 void rotate(Point center, double angle);

	//// ��������� ������������ �����
	 void reflex(Line axis);

	//// ��������� ������������ �����
	 void reflex(Point center);

	 void scale(Point center, double coef);
};