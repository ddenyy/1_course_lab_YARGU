#pragma once
#include "Header.h"
#include "Point.h"
#include "Line.h"
#include "Shape.h"

class Polygon : Shape
{
public:

	// �������� count �����. �������������� ������
	Polygon(int count, ...)
	{
		this->count_vertex = count;

		// �� �������� ������ � ���������� ����� va_list, ������� ������� ������� ���
		va_list list;

		// �� �������������� va_list � ������� va_start. ������ ��������
		// - ������ ��� �������������. ������ �������� - ��� ���������
		// �������� ����� �����������.
		va_start(list, count);

		// ���������� ��� ��������� ����������
		for (int arg = 0; arg < count; ++arg)
		{
			// �� ���������� va_arg ��� ��������� ���������� �� ������ ����������
			// ������ �������� - ��� va_list, ������� �� ����������
			// ������ �������� - ��� ��� ���������
			this->vertexs.push_back(va_arg(list, Point));
		}

		// ������� va_list, ����� ���������.
		va_end(list);
	}



	// ��������� ������������
	double dot(Point A, Point B)
	{
		return A.x * B.x + A.y * B.y;
	}

	// ��������� ������������
	double cross(Point A, Point B)
	{
		return A.x * B.y - A.y * B.x;
	}


	// �-��� �������� ������� ��������������
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

			// ���������, �� ������� �������� ����� ������� ���������� ����� �������
			double square_distance_p1_p2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
			sum += sqrt(square_distance_p1_p2);
		}
		return sum;
	}

	// ����������� ��������������. ����������� ������������� (�� ��-��) �����������
	Polygon(vector<Point> vertexs)
	{
		this->count_vertex = vertexs.size();
		this->vertexs = vertexs;
	}

	// ���� ������������ ����� ������������ ������
	int sign(Line L, Point p) {
		double eps = 1e-6;
		if (abs(L.A * p.x + L.B * p.y + L.C) >= 0) {
			return 1;
		}
		else {
			return -1;
		}
	}

	// �-��� �������� �������� �� ������������� ��� ���
	bool isConvex()
	{
		bool flag_convex = true;
		// ������� ���������� ������ ������� ����������� �� ������ ������� �����
		// ���� ���������� ����� ���������, �� ��� ������� �� ���� ������� � �������, ��������
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
				// ���� �������, �� ���� ������� �� ������, ��������� ������
				continue;
			}
			else
			{
				// ������� �������� ����� �� ��� ������� �� ���� ������� �� ������ ������ ������� �� ��������
				flag_convex = false;
				return flag_convex;
			}
		}
	}

	// �������� �� ���������� ����� ��������� ������������
	bool isConvex_v2()
	{
		/*
		����� �������� �� �������� �������������� � ��������� ��������� �������������,
		��� �� ������������ ������ � ���� �������
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

	// �-��� ������ ������. ������� � ���� � ������ ������. ���������� � ������� �����
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

	// �-��� �������� ������ � ������� ������ � cos ����� ������� ������
	void print_angles_sides(vector<double>& Angles, vector<double>& Sides)
	{
		cout << "���� = "; for (auto i : Angles) cout << i << ' ';
		cout << "===============\n";
		cout << "������� = "; for (auto i : Sides) cout << i << ' ';

		cout << '\n';
	}

	// �-��� ������ ����� � �������� ����������. ���� ��� ���� ������� => true
	bool check_equality_angles(vector<double> angle_this, vector<double> angle_another)
	{
		for (int i = 0; i < angle_this.size(); i++)
		{
			// ���� ���� ���������� ����, �� ��� �����
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

	// �-��� �������� ��� ������� �������
	// ��������������� ��� ������ ����������� ���-�� � ��� �� �������
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

	// ��������� � �������������� ������
	bool isCongruentTo(Polygon& another)
	{
		vector<double> sides_this;
		vector<double> sides_another;

		vector<double> angle_this;
		vector<double> angle_another;

		vector<Point> vertexs_another = another.getVertex();
		// ���� �� ������� ���������� ������, �� ������ ������ ������
		if (this->getCountVertex() != another.getCountVertex())
		{
			return false;
		}

		// ������� ��� ������ �� ��������, ���������� ������ ������ � �������� �����;
		round_polygon(this->vertexs, angle_this, sides_this);
		cout << "===========\n";
		round_polygon(another.vertexs, angle_another, sides_another);

		print_angles_sides(angle_this, sides_this);
		print_angles_sides(angle_another, sides_another);

		// �������� ���������� ����� �����
		if (check_equality_angles(angle_this, angle_another))
		{
			// ���� �������, �������� ������� ������
			if (check_koef_figurs(sides_this, sides_another))
			{
				// ���� ������� ��� �������, �������� ���� �������
				double koef = sides_this[0] / sides_another[0];

				if (abs(koef - 1) <= EPS)
				{
					// ��, ������ ������� � ���� ������� 1
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
			// ���� �� ��� �������, ������� ��� ������ �� �����
			return false;
		}
	}

	// �������� ��������� 
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

		// ������� ��� ������ �� ��������, ���������� ������ ������ � �������� �����;
		round_polygon(this->vertexs, angle_this, sides_this);
		cout << "===========\n";
		round_polygon(another.vertexs, angle_another, sides_another);

		// �������� ���������� ����� �����
		if (check_equality_angles(angle_this, angle_another))
		{
			// ���� �������, �������� ������� ������
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
			// ���� �� ��� �������, ������� ��� ������ �� �������
			return false;
		}
	}


	// �������� ��� ����� ������ ������
	bool containsPoint(Point point)
	{
		/*
		������ ������ ������� ��������� ��������� point.Y ����� ���������� p[i].Y � p[j].Y, 
		������������ ����������� ������� ������� � ������������ ��������� ����������� �������� �������.
		������ ������ ��������� ���������� ������� p[i]p[j] ����� �� ����� point.
		������ ������ ��������� ������������� ����� ��� ������ ���������� ������ ����� 
		� ������������� � ��� ��������.
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



	// ������� ����� ������ ������������ ������ �� ����
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

	// ��������� ������������ �����
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


	// ��������� ������������ ������
	void reflex(Line axis)
	{
		pair<Point, Point> new_view_axis = axis.transform_equation_line();
		Point a = new_view_axis.first;
		Point b = new_view_axis.second;	

		for (int i = 0; i < this->vertexs.size(); i++)
		{
			double x = vertexs[i].x;
			double y = vertexs[i].y;

			// �������� ��� ����� ������� ����� ���������� ������ �� ������ ������
			if (abs(axis.A * x + axis.B * y + axis.C) < EPS)
			{
				continue;
			}
			else
			{
				/*
				��������� ������� ������ - ��������� ���������� �� ����� �� ������,
				� ��� ���������� ��������, �� � ��������������� �������
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


