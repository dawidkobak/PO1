#ifndef FACTORY_H
#define FACTORY_H

class Factory
{
public:
	template<typename T>
	T& base(const T& a, bool flag = true)
	{
		static T object;
		if(flag)
			object = a;
		return object;
	}

	template<typename T>
	T& product()
	{
		return base<T>(T(), false);
	}
	
};

#endif