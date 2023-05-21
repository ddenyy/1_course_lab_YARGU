#pragma once
#include "Polygon.h"
#include "Circle.h"

class Triangle :
    public Polygon
{
public:

    Triangle(Point a, Point b, Point c) : Polygon(3, a, b, c) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->dist_ab = dist(a - b);
        this->dist_bc = dist(b - c);
        this->dist_ac = dist(a - c);
    };

    
    // описанная окружность
    Circle getCircumscribedCircle()
    {
        double radius_described = (dist_ab * dist_ac * dist_bc) / 4 * this->area();
        double x1 = a.x; double y1 = a.y; double x2 = b.x; double y2 = b.y; double x3 = c.x; double y3 = c.y;
        double d = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
        double xp = ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2)) / d;
        double yp = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / d;

        Point center(xp, yp);
        return Circle(center, radius_described);

    }

    Circle getInscribedScribedCircle()
    {
        double x1 = a.x; double y1 = a.y; double x2 = b.x; double y2 = b.y; double x3 = c.x; double y3 = c.y;
        double radius = (2 * area()) / (dist_ab + dist_ac + dist_bc);

        double perimert_half = (dist_ab + dist_ac + dist_bc) / 2;

        double x0 = ((x1 + x2 - 2 * x3) * ((y3 - y1) * (x2 + x3 - 2 * x1) + x1 * (y2 + y3 - 2 * y1)) - x3 * (x2 + x3 - 2 * x1) * (y1 + y2 - 2 * y3)) / ((y2 + y3 - 2 * y1) * (x1 + x2 - 2 * x3) - (x2 + x3 - 2 * x1) * (y1 + y2 - 2 * y3));
        double y0 = ((x0 - x1) * (y2 + y3 - 2 * y1) / (x2 + x3 - 2 * x1)) + y1;

        Point center(x0, y0);

        return Circle(center, radius);
    }

    // центр масс
    Point getCentroid()
    {
        Point res((a + b + c));

        res = res * (1/3);

        return res;
    }

    Point findOrthocenter()
    {
        Point centroid = getCentroid();
        Circle cicle_triangle = getCircumscribedCircle();
        Point circumcenter = cicle_triangle.getCenter();
        Point h = { (3 * centroid.x - 2 * circumcenter.x), (3 * centroid.y - 2 * circumcenter.y) };

        return h;
    }


    Line EulerLine()
    {
        Circle first_circle = getCircumscribedCircle();
        Circle second_circle = getInscribedScribedCircle();

        Point first = first_circle.getCenter();
        Point second = second_circle.getCenter();

        return Line(first, second);
    }


    Circle ninePointCircle()
    {
        Circle opisannaya = getCircumscribedCircle();

        double raduis_opisannaya = opisannaya.getRadius();

        double radiusNIEN = raduis_opisannaya / 2;


        Point center = opisannaya.getCenter();

        Point orto_center = findOrthocenter();

        Point NIEN_center = (center + orto_center) * 0.5;

        return Circle(NIEN_center, radiusNIEN);
    }

private:
    Point a;
    Point b;
    Point c;
    double dist_ab = dist(a - b);
    double dist_bc = dist(b - c);
    double dist_ac = dist(a - c);
};

