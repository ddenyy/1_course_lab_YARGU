#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stack>
#define ll long long

using namespace std;

vector<ll> Tree(800000);

vector<ll> Three_max(800000);
vector<ll> Three_min(800000);


// пересчёт for max
void change_tree_max(ll id)
{
	while (id != 1)
	{
		id /= 2;
		Three_max[id] = max(Three_max[id * 2], Three_max[id * 2 + 1]);
	}
}

// пересчет for min
// пересчёт
void change_tree_min(ll id)
{
	while (id != 1)
	{
		id /= 2;
		Three_min[id] = min(Three_min[id * 2], Three_min[id * 2 + 1]);
	}
}

ll max_three(ll id, ll tl, ll tr, ll l, ll r)
{
	if (l <= tl && tr <= r)
	{
		return Three_max[id];
	}
	if (tr <= l || r <= tl)
	{
		return 0;
	}
	ll mid = (tl + tr) / 2;
	ll info_left = max_three(id * 2, tl, mid, l, r);
	ll info_right = max_three(id * 2 + 1, mid, tr, l, r);

	return max(info_left,info_right);
}


ll min_three(ll id, ll tl, ll tr, ll l, ll r)
{
	if (l <= tl && tr <= r)
	{
		return Three_min[id];
	}
	if (tr <= l || r <= tl)
	{
		return 0;
	}
	ll mid = (tl + tr) / 2;
	ll info_left = min_three(id * 2, tl, mid, l, r);
	ll info_right = min_three(id * 2 + 1, mid, tr, l, r);

	return min(info_left, info_right);
}

int main()
{
	ifstream fin("rvq.in");
	ofstream fout("rvq.out");

	ll n;
	fin >> n;

	ll first_list = 1;
	while (first_list < n)
	{
		first_list = first_list * 2;
	}

	for (int i = 0; i < n; i++)
	{
		// запихиваем сразу элемент в лист дерева
		Three_max[i + first_list] = i*i % 12345 + i*i*i % 23456;
		Three_min[i + first_list] = i * i % 12345 + i * i * i % 23456;
		// делаем пересчёт всех элементов
		change_tree_max(i + first_list);
		change_tree_min(i + first_list);
	}

	for (ll i = 0; i < n; i++)
	{
		ll key;
		fin >> key;
		if (key < 0)
		{
			int data, id;
			fin >> data;
			id = abs(key);
			id--;
			Tree[first_list + id] = data;
			change_tree_max(first_list + id);
			change_tree_min(first_list + id);
		}
		else
		{
			ll l,r;
			l = key - 1;
			fin >> r;
			r += 1;
			fout << max_three(1, 0, first_list, 0, r) - min_three(1, 0, first_list, 0, r) << '\n';
		}
	}

}