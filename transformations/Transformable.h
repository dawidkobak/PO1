#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H

class Point;

class Transformable {
public:
	virtual ~Transformable(){};

	virtual void move(const double x, const double y) = 0;
	virtual void scale(const Point & p, const double scale) = 0;
	virtual void rotate(const Point & p, const double angle) = 0;	
	
	static const double PI;
};

#endif // TRANSFORMABLE_H
