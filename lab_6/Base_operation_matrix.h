#pragma once

#include "Header.h"


vector<int> Mark(100);
vector<int> Permuntation(100);
int count_invers = 0;
ll det = 0;

void Det_matrix(vector<vector<double>>& A, int id)
{
	if (id == A.size())
	{
		count_invers = 0;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (Permuntation[j] > Permuntation[i])
				{
					count_invers++;
				}
			}
		}
		ll multy = 1;
		for (int i = 0; i < A.size(); i++)
		{
			multy *= A[Permuntation[i]][i];
		}
		if (count_invers % 2 == 0) {
			det += multy;
		}
		else
		{
			det -= multy;
		}
	}
	else
	{
		for (int i = 0; i < A.size(); i++)
		{
			if (Mark[i] == 0)
			{
				Permuntation[id] = i;
				Mark[i] = 1;
				Det_matrix(A, id + 1);
				Mark[i] = 0;
			}
		}
	}
}

void dif_matrix(vector<vector<double>>& A, vector<vector<double>>& B, vector<vector<double>>& Res) {
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			Res[i][j] = A[i][j] - B[i][j];
		}
	}
}

void sum_matrix(vector<vector<double>>& A, vector<vector<double>>& B, vector<vector<double>>& Res)
{
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			Res[i][j] = A[i][j] + B[i][j];
		}
	}
}

void assigment_matrix(vector<vector<double>>& B, vector<vector<double>>& Res)
{
	for (int i = 0; i < B.size(); i++)
	{
		for (int j = 0; j < B[i].size(); j++)
		{
			Res[i][j] = B[i][j];
		}
	}
}

void sum_matrix_and_number(vector<vector<double>>& A, vector<vector<double>>& Res, double number) {
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[i].size(); j++)
		{
			if (i == j)
			{
				Res[i][j] = A[i][j] + number;
			}
		}
	}
}

void multy_matrix(vector<vector<double>>& A, vector<vector<double>>& B, vector<vector<double>>& Res)
{
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A.size(); j++)
		{
			for (int k = 0; k < A.size(); k++)
			{
				Res[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void mylty_elem_matrix(double alpha, vector<vector<double>>& B, vector<vector<double>>& Res)
{
	for (int i = 0; i < B.size(); i++)
	{
		for (int j = 0; j < B[i].size(); j++)
		{
			if (alpha * B[i][j] == -0 || alpha * B[i][j] == 0) {
				Res[i][j] = 0;
			}
			Res[i][j] = alpha * B[i][j];
		}
	}
}

int find_ind_max_elem_in_column(vector<vector<double> >& Matrix, int column, int size_matrix) {
	int max_position = column;
	double max = abs(Matrix[column][column]);
	for (int i = column + 1; i < size_matrix; ++i) {
		double element = abs(Matrix[i][column]);
		if (element > max) {
			max = element;
			max_position = i;
		}
	}
	return max_position;
}