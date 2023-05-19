#include "Header.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Line K(1, 1, 0);
	Point test(5, 5);

	Point A(1, 1);
	Point B(1, 4);
	Point C(4, 4);
	Point D(4, 1);

	Polygon poly(4, A, B, C, D);


	poly.scale(test, 2);

	vector<Point> arr = poly.getVertex();

	for (auto i : arr) cout << i.x << ' ' << i.y << '\n';
	
}

