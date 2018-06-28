#ifndef PUNKT_H
#define PUNKT_H

class Punkt
{
public:
	Punkt(int n_x, int n_y)
	:x(n_x), y(n_y)
	{

	}
	
	~Punkt() = default;

	template<bool T>
	int wsp() const
	{
		if(T)
			return y;
		else 
			return x;
	}

	template<typename T>
	static T min(const T& a, const T& b)
	{
		return (a < b) ? a : b;
	}

	template<typename T>
	static T max(const T& a, const T& b)
	{
		return (a < b) ? b : a;
	}

	bool operator <(const Punkt& second) const
	{
		if(x < second.x)
		{
			return true;
		}
		else if(x == second.x)
		{
			if(y < second.y)
				return true;
			else 
				return false;
		}
		else
			return false;
	}


private:
	int x;
	int y;
	
};

#endif