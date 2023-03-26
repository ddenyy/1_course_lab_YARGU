#include "Price.h"


// конструктор
Price:: Price(string nameProduct, int priceProduct, string shelfLife, vector<string> ListShop)
{
	this->nameProduct = nameProduct;
	this->priceProduct = priceProduct;
	this->ListShop = ListShop;
	this->shelfLife = shelfLife;
};

Price:: Price()
{
	this->nameProduct = "testName";
	this->priceProduct = 0;
	this->ListShop = {"test", "test", "test"};
	this->shelfLife = "00.00.00";
}

// оператор копирования
Price:: Price(const Price& other)
{
	this->ListShop = vector<string>(other.ListShop.size());
	this->nameProduct = other.nameProduct;
	this->priceProduct = other.priceProduct;
	this->shelfLife = other.shelfLife;

	for (size_t i = 0; i < other.ListShop.size(); i++)
	{
		this->ListShop[i] = other.ListShop[i];
	}
}

// деструктор
Price:: ~Price()
{
	for (size_t i = 0; i < this->ListShop.size(); i++)
	{
		this->ListShop[i].clear();
	}

	this->ListShop.clear();
	this->nameProduct.clear();
	this->shelfLife.clear();
};

//=====================================================


Price& Price::operator =(Price& other)
{
	this->nameProduct = other.nameProduct;
	this->priceProduct = other.priceProduct;
	this->shelfLife = other.shelfLife;

	this->ListShop.clear();
	this->ListShop.resize(other.ListShop.size());

	for (size_t i = 0; i < other.ListShop.size(); i++)
	{
		this->ListShop[i] = other.ListShop[i];
	}

	return *this;
}

bool Price::operator<(Price& Price1)
{
	return Price1.getPrice() > this->getPrice() || Price1.getPrice() > this->getPrice();;
}

bool Price::operator>(Price& Price1)
{
	return Price1.getPrice() < this->getPrice() || Price1.getPrice() < this->getPrice();;
}



//=====================================================

string Price:: getName()
{
	return nameProduct;
}

string Price:: getShelfLife()
{
	return this->shelfLife;
}

int Price:: getPrice()
{
	return priceProduct;
}

vector<string> Price:: getShops()
{
	return this->ListShop;
}

void Price:: setShelfLife(string shelfLife)
{
	this->shelfLife = shelfLife;
}

void Price:: setName(string name_product)
{
	this->nameProduct = name_product;
}

void Price:: setPrice(int price)
{
	this->priceProduct = price;
}

void Price::printAllInfo()
{
	cout << this->nameProduct << ' ' << this->priceProduct << ' ' << this->shelfLife << '\n';
	for (size_t i = 0; i < ListShop.size(); i++)
	{
		cout << ListShop[i] << '\n';
	}
}

bool Price:: isEmpty()
{
	if ((this->nameProduct == "testName") && (this->priceProduct == 0) && (this->shelfLife == "00.00.00"))
	{
		return true;
	}
	return false;
}

