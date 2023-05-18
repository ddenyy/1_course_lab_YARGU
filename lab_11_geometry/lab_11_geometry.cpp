#include "Header.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Line K(5, 5, 5);
	Line L(5, 5, 5);
	

	Point A(1, 1);
	Point B(1, 4);
	Point C(4, 4);
	Point D(4, 1);

	Polygon poly(4, A, B, C, D);

	Point A2(1, 1);
	Point B2(1, 6);
	Point C2(6, 6);
	Point D2(6, 1);

	Polygon poly2(4, A2, B2, C2, D2);

	vector<Point> arr = poly.getVertex();

	//for (int i = 0; i < arr.size(); i++)
	//{
	//	cout << arr[i].x << ' ' << arr[i].y << '\n';
	//}

	cout << poly.isCongruentTo(poly2) << "\n";

	
	
}

