#include <iostream>
#include "Triangle.h"

Triangle::Triangle(Point a, Point b, Point c)
:Figure(3) 
{
	table[0] = a;
	table[1] = b;
	table[2] = c;
}
	
void Triangle::print() const
{
	std::cout << "Triagle : [";
	std::cout << table[0];
	std::cout << "," << table[1];
	std::cout << "," << table[2];
	std::cout << "]\n";
}

double Triangle::area() const
{
	return 0.5 * fabs((table[0].x() - table[2].x()) * (table[1].y() - table[0].y())
		- (table[0].x() - table[1].x()) * (table[2].y() - table[0].y()));
}

double Triangle::length() const
{
	double sum = 0;

	sum += std::hypot(table[0].x() - table[1].x(), table[0].y() - table[1].y());
	sum += std::hypot(table[0].x() - table[2].x(), table[0].y() - table[2].y());
	sum += std::hypot(table[1].x() - table[2].x(), table[1].y() - table[2].y());

	return sum;
}

Triangle::Triangle(const Triangle& model)
:Figure(3)
{
	table[0] = model.table[0];
	table[1] = model.table[1];
	table[2] = model.table[2];
}