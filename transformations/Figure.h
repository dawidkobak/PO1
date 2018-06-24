#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <cmath>
#include "Transformable.h"
#include "Point.h"

class Figure: public Transformable
{
public:
	Figure(int n_points_number);

	virtual ~Figure();

	virtual double length() const;

	virtual void print() const;

	virtual void setPoint(int index, double n_x, double n_y);

	virtual void move(const double x, const double y);

	virtual void scale(const Point & p, const double scale);

	virtual void rotate(const Point & p, const double angle);


protected:
	Point* table;
	int points_number;
	
};

#endif