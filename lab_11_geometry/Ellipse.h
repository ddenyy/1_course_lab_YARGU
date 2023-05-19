#pragma once
#include "Header.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"

class Ellipse
{
public:

	Ellipse(Point focus_first, Point focus_second, double distantion) {

		// будем считать, что эллипс в канононической системе
		
		this->focus_first = focus_first;
		this->focus_second = focus_second;
		this->distantion = distantion;

		//Для того чтобы точка лежала на эллипсе, необходимо и достаточно,
		//чтобы сумма ее расстояний до фокусов равнялась большой оси эллипса 2a
		this->a = distantion / 2;

		this->c = abs(focus_first.x);

		this->eccentricity = this->c / this->a;

		this->b = sqrt(this->a * this->a - this->c * this->c);

		this->center.x = (focus_first.x + focus_second.x) / 2;
		this->center.y = (focus_first.y + focus_second.y) / 2;

	}

	pair<Point, Point> focuses()
	{
		return { focus_first, focus_second };
	}

	pair<Line, Line> directrices()
	{
		return { Line(eccentricity, 0, a), Line(eccentricity, 0, -a) };
	}

	double getEccentricity()
	{
		return this->eccentricity;
	}

	Point getCenter()
	{
		return this->center;
	}

	double perimetr()
	{
		return 2 * PI * sqrt((a * a + b * b) / 2);
	}

	double area()
	{
		return PI * a * b;
	}


	// равенство двух эллипсов
	bool isCongruentTo(Ellipse& another)
	{
		if (abs((a / another.a) - (b / another.b)) <= EPS)
		{
			if (abs(a / another.a - 1) <= EPS)
			{
				return true;
			}
		}
		return false;
	}

	bool containsPoint(Point point)
	{
		if (dist(focus_first - point) + dist(focus_second - point) <= 2 * a)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// подобие двух
	bool isSimilarTo(Ellipse& another)
	{
		if (abs((a / another.a) - (b / another.b)) <= EPS)
		{
			return true;
		}
		return false;
	}


	// поворот любой фигуры относительно центра на угол
	void rotate(Point center, double angle)
	{
		double dx = center.x;
		double dy = center.y;
		int x = focus_first.x;
		int y = focus_first.y;

		focus_first.x = ((x - dx) * cos(angle)) - ((y - dy) * sin(angle)) + dx;
		focus_first.y = ((x - dx) * sin(angle)) + ((y - dy) * cos(angle)) + dy;

		x = focus_second.x;
		y = focus_second.y;
		focus_second.x = ((x - dx) * cos(angle)) - ((y - dy) * sin(angle)) + dx;
		focus_second.y = ((x - dx) * sin(angle)) + ((y - dy) * cos(angle)) + dy;
	}

	// симметрия относительно точки
	void reflex(Point center)
	{
		// для первого и второго фокуса соотв
			Point cur = focus_first;
			Point direction_center = center - cur;
			double dist_cur_and_center = dist(direction_center);

			direction_center.x = direction_center.x / dist_cur_and_center;
			direction_center.y = direction_center.y / dist_cur_and_center;

			focus_first = center + (direction_center * dist_cur_and_center);

			cur = focus_second;
			direction_center = center - cur;
			dist_cur_and_center = dist(direction_center);

			direction_center.x = direction_center.x / dist_cur_and_center;
			direction_center.y = direction_center.y / dist_cur_and_center;

			focus_second = center + (direction_center * dist_cur_and_center);
	}

	// симметрия относительно прямой
	void reflex(Line axis)
	{
		pair<Point, Point> new_view_axis = axis.transform_equation_line();
		Point a = new_view_axis.first;
		Point b = new_view_axis.second;

		double x = focus_first.x;
		double y = focus_first.y;

		// проверка что точка которую будет отображать лежить на данной прямой
		if (abs(axis.A * x + axis.B * y + axis.C) < EPS)
		{
		}
		else
		{
			/*
			Семантика формулы такова - вычислить расстояния от точки до прямой,
			и это расстояния отложить, но в противоположную сторону
			*/

			Point ps = focus_first;

			Point n;
			n.x = a.y - b.y;
			n.y = b.x - a.x;

			double len = sqrt(n.x * n.x + n.y * n.y);
			n.x /= len;
			n.y /= len;

			double dot2 = 2 * (n.x * ps.x + n.y * ps.y);

			focus_first.x = ps.x - dot2 * n.x;
			focus_first.y = ps.y - dot2 * n.y;

			ps = focus_second;

			n;
			n.x = a.y - b.y;
			n.y = b.x - a.x;

			double len = sqrt(n.x * n.x + n.y * n.y);
			n.x /= len;
			n.y /= len;

			double dot2 = 2 * (n.x * ps.x + n.y * ps.y);

			focus_second.x = ps.x - dot2 * n.x;
			focus_second.y = ps.y - dot2 * n.y;
		}
	}

	void scale(Point center, double coef)
	{
		focus_first.x = center.x + (focus_first.x - center.x) * coef;
		focus_first.y = center.y + (focus_first.y - center.y) * coef;
		focus_second.x = center.x + (focus_second.x - center.x) * coef;
		focus_second.y = center.y + (focus_second.y - center.y) * coef;
	}


private:

	double a, b, c, eccentricity;
	double distantion;
	Point focus_first;
	Point focus_second;
	Point center;

	// вектор на который будет сдвиг системы коорд
	Point shift;
	// если у нас эллипс 'стоит' а не лежит на оси Ох
	bool flag_rotate = false;

};

