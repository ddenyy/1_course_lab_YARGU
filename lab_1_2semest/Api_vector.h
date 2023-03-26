#pragma once
#include "main.h"
#include "Price.h"

void testAllRequestDataBase(vector<Price>& DataBase);

void add_item(Price Item, int position, vector<Price>& DataBase);

void remove_item(int position, vector<Price>& DataBase);

void change_item(Price Item, int position, vector<Price>& DataBase);