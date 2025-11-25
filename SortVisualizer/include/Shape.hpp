#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#include "HandyWrapper.hpp"

struct Point {
    double x, y;
    Point(double x=0, double y=0);
};

class Shape {
    protected:
        Point base;

    public:
        Shape(double x, double y);
        virtual ~Shape();

        virtual void draw(int id, hgcolor clr = HG_BLACK) const = 0;
        virtual void drawFill(int id, hgcolor clr = HG_BLACK, int s = 0) const = 0;
};

#endif // _SHAPE_HPP_
