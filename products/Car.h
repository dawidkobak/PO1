#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car(int n_ID, const int n_seats)
	:Vehicle(n_ID), seats(n_seats) {}
	
	virtual ~Car() 
	{
		delete[] table;
	}

	void SetPassengersIds(const int* delivered_table, int n_table_size)
	{
		table_size = n_table_size;
		table = new int[table_size];
		for (int i = 0; i < table_size; ++i)
		{
			table[i] = delivered_table[i];
		}
	}

	void SetPrice(int n_price)
	{
		std::cout << "The car price will be: " << n_price << std::endl;
		Product::SetPrice(n_price);
	}

	void Drive() const
	{
		std::cout << "Driving the car with ID=" << Id() << std::endl;
	}

	virtual void Print() const
	{
		std::cout << "Car with ID=" << Id() << "  has " << table_size << " passengers with following IDs: ";
		std::cout << table[0];
		for(int i = 1; i < table_size; ++i)
		{
			std::cout << ", " << table[i];
		}
		std::cout << ". Max speed of the car is " << max_speed << std::endl;
	}

	virtual void Move() const
	{
		std::cout << "Driving the car with ID=" << Id() << std::endl;	
	}
private:
	int* table;
	int table_size;
	int seats;
	
};

#endif