#pragma once
#include "main.h"
#include "Price.h"
#include "Input.h"
#include "Output.h"
#include <algorithm>

#define all(x) x.begin(), x.end()

int find_median_price(vector<Price>& ArrayProducts);
vector<string> getShopsPriceMoreThenMedian(vector<Price>& ArrayProducts);
vector<string> getProductLongerShelfLife(string shelfLife, vector<Price>& ArrayProducts);
void sortArrayPrice(vector<Price>& ArrayProducts);

// ������� �������� � ������� ���� �������� ������ ���������, ������� �� ���������� � ��� � �������
void findProductLongerShelfLife(string shelfLife, vector<Price>& ArrayProducts);




// ��������� ������ ������� ������� �� ��
void realize_fist_task(vector<Price>& DataBase);
// ��������� ������ ������� ������� �� ��
void realize_second_task(vector<Price>& DataBase);
// ��������� ������ ������� ������� �� ��
void realize_third_task(vector<Price>& DataBase);