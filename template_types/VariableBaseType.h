#ifndef VARIABLEBASETYPE_H
#define VARIABLEBASETYPE_H

class VariableBaseType
{
public:
	virtual ~VariableBaseType() {};

	virtual void Print() const = 0;
	
};

#endif