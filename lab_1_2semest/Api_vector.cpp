#include "Api_vector.h"

// копируем из New_data в data
void copyArray(vector<Price>& New_DataBase, vector<Price>& DataBase)
{
	for (size_t i = 0; i < New_DataBase.size(); i++)
	{
		if (!New_DataBase[i].isEmpty())
		{
			DataBase.push_back(New_DataBase[i]);
		}
	}
}

bool checkValidRequest(int position, vector<Price>& DataBase)
{
	if (position >= DataBase.size() || position < 0)
	{
		cout << "выход за границы массива" << '\n';
		return false;
	}
	return true;
}

void clear_vector(vector<Price>& DataBase)
{
	for (size_t i = 0; i < DataBase.size(); i++)
	{
		DataBase[i].~Price();
	}
	DataBase.clear();
}

void remove_item(int position, vector<Price>& DataBase)
{
	vector<Price> New_DataBase(DataBase.size() - 1);

	bool valid = checkValidRequest(position, DataBase);
	if (valid)
	{	
		for (size_t i = 0; i < DataBase.size(); i++)
		{
			if (i != position && !DataBase[i].isEmpty())
			{
				New_DataBase.push_back(DataBase[i]);
			}
		}

		clear_vector(DataBase);
		copyArray(New_DataBase, DataBase);
	}
}


void add_item(Price Item, int position, vector<Price>& DataBase)
{
	bool valid = checkValidRequest(position, DataBase);
	if (valid)
	{
		vector<Price> New_DataBase;
		for (size_t i = 0; i < DataBase.size(); i++)
		{
			if (!DataBase[i].isEmpty())
			{
				if (i == position)
				{
					New_DataBase.push_back(Item);
				}
				New_DataBase.push_back(DataBase[i]);
				
			}
		}
		clear_vector(DataBase);
		copyArray(New_DataBase, DataBase);
	}
}


void change_item(Price Item, int position, vector<Price>& DataBase)
{
	bool valid = checkValidRequest(position, DataBase);
	if (valid)
	{
		DataBase[position] = Item;
	}
}



void testAllRequestDataBase(vector<Price>& DataBase)
{
	Price Test("test", 123123123, "11.11.11", { "aaa", "bbb", "ccc" });
	
	remove_item(2, DataBase);

	add_item(Test, 2, DataBase);

	change_item(Test, DataBase.size() - 1, DataBase);

	for (size_t i = 0; i < DataBase.size(); i++)
	{
		DataBase[i].printAllInfo();
		cout << '\n';
	}

}