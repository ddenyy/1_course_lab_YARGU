#include "main.h"



void output_vector_string_console(vector<string> Array)
{
	for (auto i : Array)
	{
		cout << i << '\n';
	}
}


void clear_vector(vector<string> Array)
{
	for (size_t i = 0; i < Array.size(); i++)
	{
		Array[i].clear();
	}
	Array.clear();
}