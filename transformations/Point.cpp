#include "Point.h"
#include <cmath>

Point::Point(const double x, const double y)
	: m_x(x), m_y(y)
{

}

void Point::setCoordinates(const double x, const double y)
{
	m_x = x;
	m_y = y;
}

double Point::x() const
{
	return m_x;
}

double Point::y() const
{
	return m_y;
}

void Point::move(const double x, const double y)
{
	m_x += x;
	m_y += y;
}

void Point::scale(const Point & p, const double scale)
{
	m_x = (m_x - p.m_x) * scale + p.m_x;
	m_y = (m_y - p.m_y) * scale + p.m_y;
}

void Point::rotate(const Point & p, const double angle)
{
	move(-p.m_x, -p.m_y);
	double tmpX = m_x;
	m_x = tmpX*std::cos(angle) - m_y*std::sin(angle);
	m_y = tmpX*std::sin(angle) + m_y*std::cos(angle);
	move(p.m_x, p.m_y);
	
	// for testing purposes
	if( std::abs(m_x) < 0.00001 )
		m_x = 0.0;
	if( std::abs(m_y) < 0.00001 )
		m_y = 0.0;		
}

double Point::distance(const Point & p) const
{
	return std::hypot(m_x - p.m_x, m_y - p.m_y);
}

std::ostream& operator<<(std::ostream& out, const Point & p)
{
    return out << "(" << p.m_x << ", " << p.m_y << ")"; 
}
