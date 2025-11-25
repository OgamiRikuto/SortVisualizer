#include "../include/Shape.hpp"
#include "../include/HandyWrapper.hpp"

Point::Point(double x, double y) : x(x), y(y) {}

Shape::Shape(double x, double y) : base(x, y) {}
Shape::~Shape() {};
