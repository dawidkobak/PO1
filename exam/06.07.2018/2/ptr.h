#ifndef PTR_H
#define PTR_H

template<typename T>
class ptr
{
public:
	explicit ptr(T* address = nullptr) 
	{ // kontruktor przyjmujacy adres, nie pozwala
		// na niejawne konwersje
		i = address;
	}

	operator T* () const // operator zwracający wskaźnik
	//przechowywany w klasie
	{
		return i;
	}

	bool operator != (const ptr<T>& obj) const
	// operator sprawdzający czy obiekty są różne
	// tzn czy przechowują różne adresy
	{
		if(i == obj)
			return false;
		return true;
	}

	// operator zwracający przechowywany adres
	T* operator ->() const
	{
		return i;
	}

	//operator zwracający referencję do obiektu
	const ptr<T>& operator* () const
	{
		return *this;
	}

public:
	// wkaźnik na przechowywany obiekt
	T* i;

private:
	//prywatny operator = na potrzeby error
	ptr& operator= (const ptr<T>& obj) {}
	// prywatny konstruktor kopiujący na potrzeby error
	ptr(const ptr<T>& obj) {}
}; 

#endif