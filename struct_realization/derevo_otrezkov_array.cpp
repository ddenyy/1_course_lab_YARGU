//#include <vector>
//#include <set>
//#include <map>
//#include <iostream>
//#include <string>
//#include <cmath>
//#include <stack>
//#define ll long long
//
//using namespace std;
//
//vector<ll> Tree(400000);
//
//// ��������
//void change_tree(int id)
//{
//	while (id != 1)
//	{
//		id /= 2;
//		Tree[id] = Tree[id * 2] + Tree[id * 2 + 1];
//	}
//}
//
//ll NOD(ll a, ll b)
//{
//	if (a > 0 && b > 0)
//	{
//		NOD(b, a % b);
//	}
//	else
//	{
//		return a + b;
//	}
//}
//
//ll NOD_three(int id, int tl, int tr, int l, int r)
//{
//	if (l <= tl && tr <= r)
//	{
//		return Tree[id];
//	}
//	if (tr <= l || r <= tl)
//	{
//		return 0; // ����� ������� �������
//	}
//	int mid = (tl + tr) / 2;
//	int info_left = NOD_three(id * 2, tl, mid, l, r);
//	int info_right = NOD_three(id * 2 + 1, mid, tr, l, r);
//	
//	if (info_left > 0 && info_right > 0)
//	{
//		return info_left + info_right;
//	}
//	else
//	{
//		return info_left + info_right;
//	}
//}
//
//int main()
//{
//	int n, q;
//	cin >> n >> q;
//
//	ll first_list = 1;
//	while (first_list < n)
//	{
//		first_list = first_list * 2;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		// ���������� ����� ������� � ���� ������
//		cin >> Tree[i + first_list];
//		// ������ �������� ���� ���������
//		change_tree(i + first_list);
//	}
//
//	for (int i = 0; i < q; i++)
//	{
//		int key;
//		cin >> key;
//		if (key == 2)
//		{
//			int data, id;
//			cin >> id >> data;
//			id--;
//			Tree[first_list + id] = data;
//			change_tree(first_list + id);
//		}
//		else
//		{
//			int l, r;
//			cin >> l >> r;
//			l--;
//			cout << NOD_three(1, 0, first_list, l, r) << '\n';
//		}
//	}
//	
//}