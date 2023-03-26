#include "main.h"
#pragma once

class Price
{
public:
	Price(string nameProduct, int priceProduct, string shelfLife, vector<string> ListShop);
	Price();
	Price(const Price& other);
	~Price();

	string getName();
	string getShelfLife();
	int getPrice();
	void setShelfLife(string shelfLife);
	void setName(string nameProduct);
	void setPrice(int price);
	void printAllInfo();
	bool isEmpty();
	vector<string> getShops();

	Price& operator = (Price& other);
	bool operator < (Price& Price1);
	bool operator > (Price& Price1);

private:
	string nameProduct;
	int priceProduct;
	string shelfLife;
	vector<string> ListShop;
};



