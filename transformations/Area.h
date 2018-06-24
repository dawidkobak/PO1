#ifndef AREA_H
#define AREA_H

class Area
{
public:
	Area() {}
	
	virtual ~Area() {}

	virtual double area() const = 0;
	
};

#endif