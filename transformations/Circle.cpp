#include <iostream>
#include "Circle.h"

Circle::Circle(Point centrum, double n_radius)
:Figure(1), radius(n_radius)
{
	table[0] = centrum;
}

void Circle::print() const
{
	std::cout << "Circle : O" << table[0] << ", radius = " << radius << std::endl;
}

double Circle::area() const
{
	return M_PI * radius * radius;
}

double Circle::length() const
{
	return 2 * M_PI * radius;
}

void Circle::scale(const Point & p, const double scale)
{
	for (int i = 0; i < points_number; ++i)
	{
		table[i].scale(p, scale);
	}

	radius *= scale;
}