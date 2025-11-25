#include "../include/Box.hpp"

Box::Box(double x, double y, double width, double height) : Shape(x, y), wd(width), hg(height) {}
Box::~Box() {};

void Box::draw(int id, hgcolor clr) const {
    HgWSetColor(id, clr);
    HgWBox(id, base.x, base.y, wd, hg);
}

void Box::drawFill(int id, hgcolor clr, int s) const {
    HgWSetFillColor(id, clr);
    HgWBoxFill(id, base.x, base.y, wd, hg, s);
}

void Box::update(double x, double y, double width, double height) {
    base.x = x;
    base.y = y;
    wd = width;
    hg = height;
}
