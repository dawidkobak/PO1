#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
public:
	Animal()
	:age(0) {}

	Animal(int n_age)
	:age(n_age) {}
 	
 	virtual ~Animal() {}

 	virtual void saySomething() const = 0;

 	virtual void print() const = 0;

protected:
	int age;	
};


#endif