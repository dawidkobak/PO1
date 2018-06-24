#ifndef POINT_H
#define POINT_H

#include "Transformable.h"
#include <iostream>

class Point : public Transformable {
public:
	Point(const double x = 0.0, const double y = 0.0);

	void setCoordinates(const double x = 0.0, const double y = 0.0);
	double x() const;
	double y() const;
	
	virtual void move(const double x, const double y);
	virtual void scale(const Point & p, const double scale);
	virtual void rotate(const Point & p, const double angle);	

	double distance(const Point & p) const;

public:
	friend std::ostream& operator<<(std::ostream& out, const Point & p);

private:
	double m_x;
	double m_y;
};

#endif // POINT_H
