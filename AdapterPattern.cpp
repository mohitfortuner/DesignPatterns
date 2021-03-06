// AdapterPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class AbstractTarget
{
public:
	virtual void RoundPin() = 0;
	virtual void ThreePin() = 0;
};

class Target : public AbstractTarget {
public:

	virtual void RoundPin() {
		std::cout << "I am round Pin" << "\n";
	}
	virtual void ThreePin() {
		std::cout << "I am having three pin" << "\n";
	}
};

class AbstractSwitch {
public:
	virtual void FlatPin() = 0;
	virtual void TwoPin() = 0;
};

class Switch : public AbstractSwitch
{
public:
	virtual void FlatPin() {
		std::cout << "I am Flat Pin" << "\n";
	}
	virtual void TwoPin() {
		std::cout << "I am having Two pin" << "\n";
	}
};

class Adapter : public AbstractTarget
{	
public:
	AbstractSwitch *TT;
	Adapter(AbstractSwitch *T)
	{
		TT = T;
	}
	virtual void RoundPin() {
		TT->FlatPin();
	}
	virtual void ThreePin() {
		TT->TwoPin();
	}
};

void main()
{
	Switch *l_Switch = new Switch();
	Adapter obj(l_Switch);
	obj.RoundPin();
	obj.ThreePin();
	delete l_Switch;
}