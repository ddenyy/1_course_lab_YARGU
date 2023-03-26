#pragma once
#include "main.h"
#include "Price.h"
#include "Input.h"
#include "Api.h"


void menu_swith_input_Data(vector<Price>& DataBase);

void menu_swith_action(vector<Price>& DataBase);

void print_inctruction_input();

void print_inctruction_logic_prog();

Price inputOneObjectFromConsole();

void print_inctruction_input_for_one_object();

void print_DataBase(vector<Price>& DataBase);