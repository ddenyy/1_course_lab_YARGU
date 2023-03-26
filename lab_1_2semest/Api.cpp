#include "Api.h"

// ф-ци€ подсчета средней цены по всем продуктам
int find_median_price(vector<Price>& ArrayProducts)
{
	double medianPrice = 0;

	for (size_t i = 0; i < ArrayProducts.size(); i++)
	{
		medianPrice += ArrayProducts[i].getPrice();
	}

	medianPrice /= (int)ArrayProducts.size();

	cout << "средн€€ цена = " << medianPrice << '\n';

	return medianPrice;
}


// ф-ци€ дл€ поиска в магазинах шде цена больше медианы
vector<string> getShopsPriceMoreThenMedian(vector<Price>& ArrayProducts)
{
	vector<string> Shops;
	vector<string> TmpShops;
	int median = find_median_price(ArrayProducts);

	for (size_t i = 0; i < ArrayProducts.size(); i++)
	{
		if (ArrayProducts[i].getPrice() > median)
		{
			TmpShops = ArrayProducts[i].getShops();

			for (size_t i = 0; i < TmpShops.size(); i++)
			{
				if (find(Shops.begin(), Shops.end(), TmpShops[i]) == Shops.end())
				{
					Shops.push_back(TmpShops[i]);
				}
			}
		}
	}
	return Shops;
}

// парсер дл€ перевода срока годности в дни
int parse_shelfLife_to_days(string shelfLife)
{
	string str_day;
	int num_day;
	str_day.push_back(shelfLife[0]);
	str_day.push_back(shelfLife[1]);
	num_day = stoi(str_day);

	string str_month;
	str_month.push_back(shelfLife[3]);
	str_month.push_back(shelfLife[4]);
	int num_month = stoi(str_month);

	string str_year;
	str_year.push_back(shelfLife[6]);
	str_year.push_back(shelfLife[7]);
	int num_year = stoi(str_year);

	return num_day + 30 * num_month + 365 * num_year;
}

// находит все магазины в которых продаютс€ товары с сроком годности больше данного
vector<string> getProductLongerShelfLife(string shelfLife, vector<Price>& ArrayProducts)
{
	vector<string> ListShopsMoreLife;
	
	int main_shelfLife = parse_shelfLife_to_days(shelfLife);

	for (size_t i = 0; i < ArrayProducts.size(); i++)
	{
		string cur_product_life = ArrayProducts[i].getShelfLife();
		vector<string> Current_Shops = ArrayProducts[i].getShops();
		
		int current_shelfLife = parse_shelfLife_to_days(cur_product_life);
		
		if (current_shelfLife > main_shelfLife)
		{
			for (size_t i = 0; i < Current_Shops.size(); i++)
			{
				if (find(all(ListShopsMoreLife), Current_Shops[i]) == ListShopsMoreLife.end()) 
				{
					ListShopsMoreLife.push_back(Current_Shops[i]);
				}
			}
		}
	}
	return ListShopsMoreLife;
}

// находит продукты у которых срок годности больше заданного, выводит всЄ информацию о них в консоль
void findProductLongerShelfLife(string shelfLife, vector<Price>& ArrayProducts)
{
	int main_shelfLife = parse_shelfLife_to_days(shelfLife);
	for (size_t i = 0; i < ArrayProducts.size(); i++)
	{
		string cur_product_life = ArrayProducts[i].getShelfLife();
		vector<string> Current_Shops = ArrayProducts[i].getShops();

		int current_shelfLife = parse_shelfLife_to_days(cur_product_life);

		if (current_shelfLife > main_shelfLife)
		{
			ArrayProducts[i].printAllInfo();
			cout << "\n\n";
		}
	}

}


// ф-ци€ сортировки массива объектов класса Price
void sortArrayPrice(vector<Price>& ArrayProducts)
{
	// напишем прост сортировку пузырьком
	for (int i = 0; i < ArrayProducts.size(); i++) {
		for (int j = 0; j < ArrayProducts.size() - 1; j++) {
			if (ArrayProducts[j] > ArrayProducts[j + 1]) {
				Price b = ArrayProducts[j]; // создали дополнительную переменную
				ArrayProducts[j] = ArrayProducts[j + 1]; // мен€ем местами
				ArrayProducts[j + 1] = b; // значени€ элементов
			}
		}
	}

}


// выполн€ет логику первого задани€ из тз
void realize_fist_task(vector<Price>& DataBase)
{
	sortArrayPrice(DataBase);
	for (auto current_Price_object : DataBase)
	{
		current_Price_object.printAllInfo();
		cout << "\n\n";
	}
}

// выполн€ет логику второго задани€ из тз
void realize_second_task(vector<Price>& DataBase)
{
	cout << "введите дату в формате дд.мм.гг" << '\n';
	string shelfLife;
	cin >> shelfLife;
	vector<string> List_Shops_More_Life_shelf = getProductLongerShelfLife(shelfLife, DataBase);
	cout << "все магазины в которых есть товары со сроком больше данного >> \n";
	output_vector_string_console(List_Shops_More_Life_shelf);
	cout << "\n\n»нформаци€ о каждом таком продукте >>\n";
	findProductLongerShelfLife(shelfLife, DataBase);

}

// выполн€ет логику третьго задани€ из тз
void realize_third_task(vector<Price>& DataBase)
{
	vector<string> Shop_more_median = getShopsPriceMoreThenMedian(DataBase);
	output_vector_string_console(Shop_more_median);
}