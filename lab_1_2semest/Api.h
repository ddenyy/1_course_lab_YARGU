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

// находит продукты у которых срок годности больше заданного, выводит всё информацию о них в консоль
void findProductLongerShelfLife(string shelfLife, vector<Price>& ArrayProducts);




// выполняет логику первого задания из тз
void realize_fist_task(vector<Price>& DataBase);
// выполняет логику второго задания из тз
void realize_second_task(vector<Price>& DataBase);
// выполняет логику третьго задания из тз
void realize_third_task(vector<Price>& DataBase);