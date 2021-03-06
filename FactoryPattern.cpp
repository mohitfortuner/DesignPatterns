// FactoryPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

enum class Location {
	Bundi,
	Kota,
	Mumbai
};

class IDistributor{
public:
	virtual void ShipBook() = 0;
};

class BundiDistributor : public IDistributor {
public:
	void ShipBook() {
		std::cout << "BundiDistributor" << "\n";
	}
};

class KotaDistributor : public IDistributor {
public:
	void ShipBook() {
		std::cout << "KotaDistributor" << "\n";
	}
};

class MumbaiDistributor : public IDistributor {
public:
	void ShipBook() {
		std::cout << "MumbaiDistributor" << "\n";
	}
};

// Book Stores...
class IBookStore {
public:
	virtual IDistributor* BookStore() = 0;
};

class BookStoreA : public IBookStore {
	Location location;
public:
	BookStoreA(Location f_location)
	{
		location = f_location;
	}

	IDistributor* BookStore()
	{
		if (location == Location::Bundi)
			return new BundiDistributor();
		else if (location == Location::Kota)
			return new KotaDistributor();
		else if (location == Location::Mumbai)
			return new MumbaiDistributor();

		return nullptr;
	}
};

void main()
{
	IBookStore * bookStore = new BookStoreA(Location::Bundi);
	auto distributor = bookStore->BookStore();
	distributor->ShipBook();

	 bookStore = new BookStoreA(Location::Kota);
	 distributor = bookStore->BookStore();
	distributor->ShipBook();

	bookStore = new BookStoreA(Location::Mumbai);
	 distributor = bookStore->BookStore();
	distributor->ShipBook();
}