#include "Input.h"

vector<Price> inputFromFile(string name_file)
{
	ifstream fin(name_file);
	int countProducts;
	string nameProduct;
	int priceProduct;
	string shelfLife;
	int sizeShops;
	vector<string> List_shop;
	string tmp;

	fin >> countProducts;
	vector<Price> DataBaseProducts(countProducts);

	for (int i = 0; i < countProducts; i++)
	{
		fin >> nameProduct >> priceProduct;
		fin >> shelfLife;
		fin >> sizeShops;

		List_shop.resize(sizeShops);

		for (int i = 0; i < sizeShops; i++)
		{
			fin >> List_shop[i];
		}
		Price cur_product(nameProduct, priceProduct, shelfLife, List_shop);
		DataBaseProducts[i] = cur_product;
	}

	return DataBaseProducts;
}

vector<Price> inputFromConsole()
{
	int countProducts;
	string nameProduct;
	int priceProduct;
	string shelfLife;
	int sizeShops;
	vector<string> List_shop;
	string tmp;

	cin >> countProducts;
	vector<Price> DataBaseProducts(countProducts);

	for (int i = 0; i < countProducts; i++)
	{
		cin >> nameProduct >> priceProduct;
		cin >> shelfLife;
		cin >> sizeShops;

		List_shop.resize(sizeShops);

		for (int i = 0; i < sizeShops; i++)
		{
			cin >> List_shop[i];
		}
		Price cur_product(nameProduct, priceProduct, shelfLife, List_shop);
		DataBaseProducts[i] = cur_product;
	}

	return DataBaseProducts;
}


Price inputOneObjectFromConsole()
{
	int countProducts;
	string nameProduct;
	int priceProduct;
	string shelfLife;
	int sizeShops;
	vector<string> List_shop;

	cin >> nameProduct >> priceProduct;
	cin >> shelfLife;
	cin >> sizeShops;

	List_shop.resize(sizeShops);

	for (int i = 0; i < sizeShops; i++)
	{
		cin >> List_shop[i];
	}
	Price cur_product(nameProduct, priceProduct, shelfLife, List_shop);

	return cur_product;
}

