#include <iostream>
#include "Figure.h"

Figure::Figure(int n_points_number)
:table(new Point[n_points_number]), points_number(n_points_number) 
{

}
	
Figure::~Figure()
{
	delete[] table;
}

double Figure::length() const
{
	return std::hypot(table[0].x() - table[1].x(), table[0].y() - table[1].y());
}

void Figure::print() const
{
	std::cout << "Figure : [";
	std::cout << table[0];
	for(int i = 1; i < points_number; ++i)
	{
		std::cout << "," << table[i];
	}
	std::cout << "]\n";
}

void Figure::setPoint(int index, double n_x, double n_y)
{
	table[index].setCoordinates(n_x, n_y);
}

void Figure::move(const double x, const double y)
{
	for (int i = 0; i < points_number; ++i)
	{
		table[i].move(x, y);
	}
}

void Figure::scale(const Point & p, const double scale)
{
	for (int i = 0; i < points_number; ++i)
	{
		table[i].scale(p, scale);
	}
}

void Figure::rotate(const Point & p, const double angle)
{
	for (int i = 0; i < points_number; ++i)
	{
		table[i].rotate(p, angle);
	}
}