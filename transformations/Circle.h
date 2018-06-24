#ifndef CIRCLE_H
#define CIRCLE_H

#include "Area.h"
#include "Figure.h"
#include "Point.h"
#include <cmath>

class Circle: public Figure, public Area
{
public:
	Circle(Point centrum, double n_radius);

	virtual void print() const;
	
	virtual ~Circle() {}

	virtual double area() const;

	virtual double length() const;

	virtual void scale(const Point & p, const double scale);
	
private:
	double radius;

};

#endif