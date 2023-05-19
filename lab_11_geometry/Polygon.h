#pragma once
#include "Header.h"
#include "Point.h"
#include "Line.h"
#include "Shape.h"

class Polygon : Shape
{
public:

	// получаем count точек. инициализируем фигуру
	Polygon(int count, ...)
	{
		this->count_vertex = count;

		// Мы получаем доступ к многоточию через va_list, поэтому давайте объявим его
		va_list list;

		// Мы инициализируем va_list с помощью va_start. Первый параметр
		// - список для инициализации. Второй параметр - это последний
		// параметр перед многоточием.
		va_start(list, count);

		// Перебираем все аргументы многоточия
		for (int arg = 0; arg < count; ++arg)
		{
			// Мы используем va_arg для получения параметров из нашего многоточия
			// Первый параметр - это va_list, который мы используем
			// Второй параметр - это тип параметра
			this->vertexs.push_back(va_arg(list, Point));
		}

		// Очищаем va_list, когда закончили.
		va_end(list);
	}



	// скалярное произведение
	double dot(Point A, Point B)
	{
		return A.x * B.x + A.y * B.y;
	}

	// векторное произведение
	double cross(Point A, Point B)
	{
		return A.x * B.y - A.y * B.x;
	}


	// ф-ция подсчета площади многоугольника
	double area()
	{
		double res = 0;
		for (int i = 0; i < vertexs.size(); i++)
		{
			Point
				p1 = i ? vertexs[i - 1] : vertexs.back(),
				p2 = vertexs[i];
			res += (p1.x - p2.x) * (p1.y + p2.y);
		}
		return fabs(res) / 2;
	}

	double perimetr()
	{
		double sum = 0;
		for (int i = 0; i < vertexs.size(); i++)
		{
			Point
				p1 = i ? vertexs[i - 1] : vertexs.back(),
				p2 = vertexs[i];
			Line cur(p1, p2);

			// костыльно, но считаем периметр через квадрат расстояния между точками
			double square_distance_p1_p2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
			sum += sqrt(square_distance_p1_p2);
		}
		return sum;
	}

	// конструктор многоугольника. Минимальный многоугольник (на пл-ти) треугольник
	Polygon(vector<Point> vertexs)
	{
		this->count_vertex = vertexs.size();
		this->vertexs = vertexs;
	}

	// знак расположения точки относительно прямой
	int sign(Line L, Point p) {
		double eps = 1e-6;
		if (abs(L.A * p.x + L.B * p.y + L.C) >= 0) {
			return 1;
		}
		else {
			return -1;
		}
	}

	// ф-ция проверки выпуклый ли многоугольник или нет
	bool isConvex()
	{
		bool flag_convex = true;
		// считаем количество вершин которые расположены по разные стороны линии
		// если количество равно исходному, то все вершины по одну сторону и многоуг, выпуклый
		int count_vertex_line = 0;

		for (int i = 0; i < vertexs.size(); i++)
		{
			Point
				p1 = i ? vertexs[i - 1] : vertexs.back(),
				p2 = vertexs[i];

			Line egle(p1, p2);

			for (int i = 0; i < vertexs.size(); i++)
			{
				count_vertex_line += sign(egle, vertexs[i]);
			}

			if (count_vertex_line == vertexs.size())
			{
				count_vertex_line = 0;
				// весь многоуг, по одну сторону от прямой, проверяем дальше
				continue;
			}
			else
			{
				// поймали ситуацию когда не все вершины по одну сторону от прямой значит прямоуг не выпуклый
				flag_convex = false;
				return flag_convex;
			}
		}
	}

	// проверка на выпуклость через векторное произведение
	bool isConvex_v2()
	{
		/*
		Можно пройтись по сторонам многоугольника и проверять векторным произведением,
		что мы поворачиваем всегда в одну сторону
		*/

		double cross_prev = NULL;

		Point a = this->vertexs[0];
		Point b = this->vertexs[1];

		for (int i = 2; i < this->vertexs.size(); i++)
		{
			Point c = this->vertexs[i];

			if (cross_prev == NULL)
			{
				cross_prev = cross(b - a, c - a);
			}

			if (cross(b - a, c - a) * cross_prev > 0)
			{
				continue;
			}
			else
			{
				return false;
			}
			a = b;
			b = c;
		}
		return true;
	}

	vector<Point> getVertex()
	{
		return this->vertexs;
	}


	int getCountVertex()
	{
		return count_vertex;
	}

	double dist(Point a)
	{
		return sqrt(a.x * a.x + a.y * a.y);
	}

	// ф-ция обхода фигуры. считает её углы и длинны сторон. записывает в массивы соотв
	void round_polygon(vector<Point>& vertexs, vector<double>& Angles, vector<double>& Sides)
	{
		Point prev1 = NULL;
		Point prev2 = NULL;

		for (int i = 0; i < vertexs.size(); i++)
		{
			double angle = 0;
			Point p1;
			Point p2;
			Point A;
			Point B;

			if (i == vertexs.size() - 1)
			{
				p1 = vertexs[i];
				p2 = vertexs[0];
			}
			else
			{
				p1 = vertexs[i];
				p2 = vertexs[i + 1];
			}

			if (prev1 == NULL && prev2 == NULL)
			{
				prev1 = p1;
				prev2 = p2;
			}
			else
			{
				Point A = p2 - p1;
				Point B = prev1 - prev2;
				angle = dot(A, B) / (sqrt(A.x * A.x + A.y * A.y) * sqrt(B.x * B.x + B.y * B.y));

				cout << angle << '\n';
				
				Angles.push_back(angle);

				prev1 = p1;
				prev2 = p2;
			}

			Sides.push_back(dist(p2 - p1));
			cout << p1.x << ' ' << p1.y << '|' << ' ' << p2.x << ' ' << p2.y << '\n';
		}
	}

	// ф-ция простого вывода в консоль сторон и cos углов текущей фигуры
	void print_angles_sides(vector<double>& Angles, vector<double>& Sides)
	{
		cout << "углы = "; for (auto i : Angles) cout << i << ' ';
		cout << "===============\n";
		cout << "стороны = "; for (auto i : Sides) cout << i << ' ';

		cout << '\n';
	}

	// ф-ция обхода углов и проверки совпадения. если все углы совпали => true
	bool check_equality_angles(vector<double> angle_this, vector<double> angle_another)
	{
		for (int i = 0; i < angle_this.size(); i++)
		{
			// если углы отличаются мало, то они равны
			if (abs(angle_another[i] - angle_this[i]) <= EPS)
			{
				continue;
			}
			else
			{
				return false;
			}
		}
	}

	// ф-ция проверки что стороны подобны
	// подразумевается что сторон одиннаковое кол-во и они не нулевые
	bool check_koef_figurs(vector<double>& sides_this, vector<double>& sides_another)
	{
		double prev_koef = sides_this[0] / sides_another[0];

		for (int i = 1; i < sides_this.size(); i++)
		{
			double cur_koef = sides_this[i] / sides_another[i];

			if (cur_koef == prev_koef)
			{
				continue;
			}
			else
			{
				false;
			}
		}
		return true;
	}

	// сравнение в геометрическом смысле
	bool isCongruentTo(Polygon& another)
	{
		vector<double> sides_this;
		vector<double> sides_another;

		vector<double> angle_this;
		vector<double> angle_another;

		vector<Point> vertexs_another = another.getVertex();
		// если не совпали количество вершин, то точняк разные фигуры
		if (this->getCountVertex() != another.getCountVertex())
		{
			return false;
		}

		// обходим две фигуры по контруру, записываем длинны сторон и косинусы углов;
		round_polygon(this->vertexs, angle_this, sides_this);
		cout << "===========\n";
		round_polygon(another.vertexs, angle_another, sides_another);

		print_angles_sides(angle_this, sides_this);
		print_angles_sides(angle_another, sides_another);

		// проверим совпадение углов фигур
		if (check_equality_angles(angle_this, angle_another))
		{
			// углы совпали, проверим подобие сторон
			if (check_koef_figurs(sides_this, sides_another))
			{
				// если стороны все подобны, проверим коэф подобия
				double koef = sides_this[0] / sides_another[0];

				if (abs(koef - 1) <= EPS)
				{
					// да, фигуры подобны с коэф подобия 1
					return true;
				}
				else
				{
					return false;
				}

			}
			else
			{
				return false;
			}
		}
		else
		{
			// углы не все совпали, фигурки уже точняк не равны
			return false;
		}
	}

	// оператор сравнения 
	bool operator == (Polygon& another)
	{
		if (this->isCongruentTo(another))
		{
			return true;
		}
		return false;

	}


	bool isSimilarTo(Polygon& another)
	{
		vector<double> sides_this;
		vector<double> sides_another;

		vector<double> angle_this;
		vector<double> angle_another;

		// обходим две фигуры по контруру, записываем длинны сторон и косинусы углов;
		round_polygon(this->vertexs, angle_this, sides_this);
		cout << "===========\n";
		round_polygon(another.vertexs, angle_another, sides_another);

		// проверим совпадение углов фигур
		if (check_equality_angles(angle_this, angle_another))
		{
			// углы совпали, проверим подобие сторон
			if (check_koef_figurs(sides_this, sides_another))
			{
				return true;

			}
			else
			{
				return false;
			}
		}
		else
		{
			// углы не все совпали, фигурки уже точняк не подобны
			return false;
		}
	}


	// проверка что точка внутри фигуры
	bool containsPoint(Point point)
	{
		/*
		Первая строка условия проверяет попадание point.Y между значениями p[i].Y и p[j].Y, 
		контролирует направление прохода вершины и обеспечивает ненулевой знаменатель основной формулы.
		Вторая строка проверяет нахождение стороны p[i]p[j] слева от точки point.
		Третья строка формирует отрицательный ответ при чётном количестве сторон слева 
		и положительный — при нечётном.
		*/
		bool result = false;
		int j = this->vertexs.size() - 1;
		for (int i = 0; i < this->vertexs.size(); i++) {
			if ((this->vertexs[i].y < point.y && this->vertexs[j].y >= point.y || this->vertexs[j].y < point.y && this->vertexs[i].y >= point.y) &&
				(this->vertexs[i].x + (point.y - this->vertexs[i].y) / (this->vertexs[j].y - this->vertexs[i].y) * (this->vertexs[j].x - this->vertexs[i].x) < point.x))
				result = !result;
			j = i;
		}

		return result;
	}



	// поворот любой фигуры относительно центра на угол
	void rotate(Point center, double angle)
	{
		double dx = center.x;
		double dy = center.y;

		for (int i = 0; i < this->vertexs.size(); i++)
		{
			int x = this->vertexs[i].x;
			int y = this->vertexs[i].y;
			this->vertexs[i].x = ((x - dx) * cos(angle)) - ((y - dy) * sin(angle)) + dx;
			this->vertexs[i].y = ((x - dx) * sin(angle)) + ((y - dy) * cos(angle)) + dy;
		}
	}

	// симметрия относительно точки
	void reflex(Point center)
	{
		for (int i = 0; i < this->vertexs.size(); i++)
		{
			Point cur = this->vertexs[i];
			Point direction_center = center - cur;
			double dist_cur_and_center = dist(direction_center);

			direction_center.x = direction_center.x / dist_cur_and_center;
			direction_center.y = direction_center.y / dist_cur_and_center;

			this->vertexs[i] = center + (direction_center * dist_cur_and_center);

		}
	}


	// симметрия относительно прямой
	void reflex(Line axis)
	{
		pair<Point, Point> new_view_axis = axis.transform_equation_line();
		Point a = new_view_axis.first;
		Point b = new_view_axis.second;	

		for (int i = 0; i < this->vertexs.size(); i++)
		{
			double x = vertexs[i].x;
			double y = vertexs[i].y;

			// проверка что точка которую будет отображать лежить на данной прямой
			if (abs(axis.A * x + axis.B * y + axis.C) < EPS)
			{
				continue;
			}
			else
			{
				/*
				Семантика формулы такова - вычислить расстояния от точки до прямой,
				и это расстояния отложить, но в противоположную сторону
				*/

				Point ps = this->vertexs[i];

				Point n;
				n.x = a.y - b.y;
				n.y = b.x - a.x;

				double len = sqrt(n.x * n.x + n.y * n.y);
				n.x /= len;
				n.y /= len;

				double dot2 = 2 * (n.x * ps.x + n.y * ps.y);

				this->vertexs[i].x = ps.x - dot2 * n.x;
				this->vertexs[i].y = ps.y - dot2 * n.y;
			}
		}
	}


	void scale(Point center, double coef)
	{
		for (int i = 0; i < vertexs.size(); i++)
		{
			vertexs[i].x = center.x + (vertexs[i].x - center.x) * coef;
			vertexs[i].y = center.y + (vertexs[i].y - center.y) * coef;
		}
	}



private:
	int count_vertex = 0;

	vector<Point> vertexs;

};


