#pragma once
#include "Header.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"

class Square:
    public Rectangle
{
    Square(Point bottom_left, Point top_right) : Rectangle(bottom_left, top_right) {};


    // вписанный круг
    Circle getInscribedScribedCircle()
    {
        Point center = this->getCenter();

        double dist_side = dist(this->top_left - this->top_right);

        double radius = dist_side / 2;

        return Circle(center, radius);
    }

    // описанная окружность
    Circle getCircumscribedCircle()
    {
        Point center = this->getCenter();

        double dist_side = dist(this->top_left - this->bottom_right);

        double radius = dist_side / 2;

        return Circle(center, radius);
    }



};

