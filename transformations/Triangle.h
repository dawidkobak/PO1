#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Area.h"
#include "Figure.h"
#include "Point.h"

class Triangle: public Figure, public Area
{
public:
	Triangle(Point a, Point b, Point c);
	
	virtual ~Triangle() {}
	
	virtual void print() const;

	virtual double area() const;

	virtual double length() const;

	Triangle(const Triangle& model);
	
};

#endif