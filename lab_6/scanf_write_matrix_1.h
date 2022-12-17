#pragma once
#pragma once
#include "Header.h"

void write_matrix_console(vector<vector<double>>& A)
{
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

void write_matrix_file(string file_name, vector<vector<double>>& A)
{
	ofstream out(file_name);
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			out << A[i][j] << ' ';
		}
		out << '\n';
	}
	out.close();
}

void clear_matrix(vector<vector<double>>& A)
{
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size();)
		{
			A[i].pop_back();
		}
	}
	for (int i = 0; i < A.size();)
	{
		A.pop_back();
	}
}

void init_matrix(int n, vector<vector<double> >& A)
{
	vector<double>B;
	for (int i = 0; i < n; i++)
	{
		A.push_back(B);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i].push_back(0);
		}
	}
}

void scanf_matrix_console(int& n, vector<vector<double>>& A)
{
	cin >> n;
	clear_matrix(A);
	init_matrix(n, A);
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			cin >> A[i][j];
		}
	}
}


void scanf_matrix_file(string file_name, int& n, vector<vector<double>>& A)
{
	ifstream in(file_name);
	in >> n;
	clear_matrix(A);
	init_matrix(n, A);
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			in >> A[i][j];
		}
	}
	in.close();
}

bool check_matrix(vector<vector<double>>& A) {
	bool flag = true;
	for (int i = 0; i < A.size(); i++)
	{
		if (A.size() != A[i].size()) {
			flag = false;
		}
	}
	return flag;
}