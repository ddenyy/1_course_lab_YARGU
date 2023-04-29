//#include <vector>
//#include <set>
//#include <map>
//#include <iostream>
//#include <string>
//#include <cmath>
//#include <stack>
//
//
//using namespace std;
//
//
//struct bin_three {
//	int info;
//	bin_three* left = NULL; 
//	bin_three* right = NULL;
//	// предыдущий
//	bin_three* pred = NULL;
//};
//
//void init(bin_three* root)
//{
//	root->left = NULL;
//	root->right = NULL;
//	root->pred = NULL;
//	cout << "scanf data: ";
//	int data;
//	cin >> data;
//	root->info = data;
//}
//
//void insert_three(bin_three* Node, int data)
//{
//	if (Node->info > data)
//	{
//		if (Node->left != NULL)
//		{
//			insert_three(Node->left, data);
//		}
//		else
//		{
//			bin_three* Node_left = new bin_three;
//
//			Node->left = Node_left;
//			Node_left->pred = Node;
//			Node_left->info = data;
//		}
//	} 
//	else if (Node->info < data)
//	{
//		if (Node->right != NULL)
//		{
//			insert_three(Node->right, data);
//		}
//		else
//		{
//			bin_three* Node_right = new bin_three;
//			Node->right = Node_right;
//			Node_right->pred = Node;
//			Node_right->info = data;
//		}
//	}
//}
//
//void show(bin_three* Node, int level)
//{
//	if (Node->left != NULL)
//	{
//		show(Node->left, level + 1); 
//	}
//	for (int i = 0; i < level; i++)
//	{
//		cout << "    ";
//	}
//	cout << Node->info << '\n';
//
//	if (Node->right != NULL)
//	{
//		show(Node->right, level + 1);
//	}
//}
//
//void dfs(bin_three* Node, bool& flag, int data)
//{
//	if (Node->info == data)
//	{
//		flag = true;
//	}
//	if (Node->info < data)
//	{
//		if (Node->left!= NULL && flag == false)
//		{
//			dfs(Node->left, flag, data);
//		}
//	}
//	if (Node->info > data)
//	{
//		if (Node->right != NULL && flag == false)
//		{
//			dfs(Node->right, flag, data);
//		}
//	}
//	
//}
//
//int main()
//{
//	bin_three* root = new bin_three;
//
//	root->info = 10;
//	insert_three(root, 5);
//	insert_three(root, 2);
//	insert_three(root, 12);
//	insert_three(root, 11);
//	insert_three(root, 45);
//	insert_three(root, 14);
//	insert_three(root, 2);
//	insert_three(root, 6);
//	insert_three(root, 90);
//	insert_three(root, 9);
//	insert_three(root, 7);
//	insert_three(root, 8);
//	show(root, 0);
//}