#include "Api.h"

// �-��� �������� ������� ���� �� ���� ���������
int find_median_price(vector<Price>& ArrayProducts)
{
	double medianPrice = 0;

	for (size_t i = 0; i < ArrayProducts.size(); i++)
	{
		medianPrice += ArrayProducts[i].getPrice();
	}

	medianPrice /= (int)ArrayProducts.size();

	cout << "������� ���� = " << medianPrice << '\n';

	return medianPrice;
}


// �-��� ��� ������ � ��������� ��� ���� ������ �������
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

// ������ ��� �������� ����� �������� � ���
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

// ������� ��� �������� � ������� ��������� ������ � ������ �������� ������ �������
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

// ������� �������� � ������� ���� �������� ������ ���������, ������� �� ���������� � ��� � �������
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


// �-��� ���������� ������� �������� ������ Price
void sortArrayPrice(vector<Price>& ArrayProducts)
{
	// ������� ����� ���������� ���������
	for (int i = 0; i < ArrayProducts.size(); i++) {
		for (int j = 0; j < ArrayProducts.size() - 1; j++) {
			if (ArrayProducts[j] > ArrayProducts[j + 1]) {
				Price b = ArrayProducts[j]; // ������� �������������� ����������
				ArrayProducts[j] = ArrayProducts[j + 1]; // ������ �������
				ArrayProducts[j + 1] = b; // �������� ���������
			}
		}
	}

}


// ��������� ������ ������� ������� �� ��
void realize_fist_task(vector<Price>& DataBase)
{
	sortArrayPrice(DataBase);
	for (auto current_Price_object : DataBase)
	{
		current_Price_object.printAllInfo();
		cout << "\n\n";
	}
}

// ��������� ������ ������� ������� �� ��
void realize_second_task(vector<Price>& DataBase)
{
	cout << "������� ���� � ������� ��.��.��" << '\n';
	string shelfLife;
	cin >> shelfLife;
	vector<string> List_Shops_More_Life_shelf = getProductLongerShelfLife(shelfLife, DataBase);
	cout << "��� �������� � ������� ���� ������ �� ������ ������ ������� >> \n";
	output_vector_string_console(List_Shops_More_Life_shelf);
	cout << "\n\n���������� � ������ ����� �������� >>\n";
	findProductLongerShelfLife(shelfLife, DataBase);

}

// ��������� ������ ������� ������� �� ��
void realize_third_task(vector<Price>& DataBase)
{
	vector<string> Shop_more_median = getShopsPriceMoreThenMedian(DataBase);
	output_vector_string_console(Shop_more_median);
}