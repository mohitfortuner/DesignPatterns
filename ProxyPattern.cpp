// ProxyPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

// Proxy interface, that should be inherited by both the proxy class (clients target)  and Real Car object...
class ICar
{
public: 
	virtual void MoveCar() = 0;
};

class Car : public ICar {
public:
	void MoveCar() {
		std::cout << "You are allowed to drive" << "\n";
	}
};

class Driver
{
public:
	int age;
	Driver() = default;
	Driver(int a) {
		age = a;
	}
};

class CarProxy : public ICar {
	Car car;
	Driver driver;
public:
	CarProxy(Driver f_driver) {
		driver = f_driver;
	}
	void MoveCar()
	{
		if (driver.age < 16)
			std::cout << "You are not allowed to drive" << "\n";
		else
			car.MoveCar();
	}
};


void main()
{
	ICar *obj = new CarProxy(Driver(10));
	obj->MoveCar();
	delete obj;
	obj = nullptr;

	obj = new CarProxy(Driver(20));
	obj->MoveCar();
	delete obj;
}