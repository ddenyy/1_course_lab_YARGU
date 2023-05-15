#include "Header.h"

struct Train
{
	string destination_point = "";
	int start_time = 0;
	int serial_number = 0;
};

// узел дерева AVL
class AVLNode {
public:
	vector<Train> trains;
	AVLNode* left;
	AVLNode* right;
	// глубина
	int depth;
};

// max int int
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else {
		return b;
	}
}

// ф-ция получения глубины элемента
int depth(AVLNode* elem)
{
	if (elem == NULL)
	{
		return 0;
	}
	return elem->depth;
}

// создание нового узла
AVLNode* newNode(Train train)
{
	AVLNode* node = new AVLNode();
	node->trains.push_back(train);
	node->left = NULL;
	node->right = NULL;
	node->depth = 1; // добавили как лист в дерево
	return node;
}

// поворот вправо поддерева с корнем
AVLNode* rightRotate(AVLNode* y)
{
	AVLNode* x = y->left;
	AVLNode* T2 = x->right;

	// вращение
	x->right = y;
	y->left = T2;


	y->depth = max(depth(y->left), depth(y->right)) + 1;
	x->depth = max(depth(x->left), depth(x->right)) + 1;

	// x стал корнем
	return x;
}

// поворот дерева с корнем х
AVLNode* leftRotate(AVLNode* x)
{
	AVLNode* y = x->right;
	AVLNode* T2 = y->left;

	// вращение влево
	y->left = x;
	x->right = T2;

	x->depth = max(depth(x->left), depth(x->right)) + 1;
	y->depth = max(depth(y->left), depth(y->right)) + 1;

	return y;
}

int getBalance(AVLNode* elem)
{
	if (elem == NULL)
	{
		return 0;
	}
	else
	{
		return depth(elem->left) - depth(elem->right);
	}
}

// операции добавления (вставка для узла)
AVLNode* insert(AVLNode* node, Train train)
{
	if (node == NULL)
	{
		return newNode(train);
	}

	if (train.destination_point < node->trains[0].destination_point) // уход влево
	{
		node->left = insert(node->left, train);
	}
	else if (train.destination_point > node->trains[0].destination_point) // уход вправо
	{
		node->right = insert(node->right, train);
	}
	else // равные значения с узлом
	{
		node->trains.push_back(train);
		return node;
	}

	// обновили глубину текущего узла
	node->depth = 1 + max(depth(node->left), depth(node->right));

	int balance = getBalance(node);

	// поворот вправо и вправо
	if (balance < -1 && train.destination_point > node->right->trains[0].destination_point)
	{
		return leftRotate(node);
	}
	// поворот лево и лево
	if (balance > 1 && train.destination_point < node->left->trains[0].destination_point)
	{
		return rightRotate(node);
	}

	// поворот лево право
	if (balance > 1 && train.destination_point > node->left->trains[0].destination_point)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// право лево
	if (balance < -1 && train.destination_point < node->right->trains[0].destination_point)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

AVLNode* minValueNode(AVLNode* node)
{
	AVLNode* current = node;
	// найти крайний левый лист
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}



AVLNode* deleteNode(AVLNode* root, Train train)
{
	if (root == NULL)
	{
		return root;
	}

	if (train.destination_point < root->trains[0].destination_point)
	{
		root->left = deleteNode(root->left, train);
	}
	else if (train.destination_point > root->trains[0].destination_point)
	{
		root->right = deleteNode(root->right, train);
	}
	else
	{
		// узел только с одним дочерним элементом или без дочернего эл-та
		if ((root->left == NULL) || (root->right == NULL))
		{
			AVLNode* temp = root->left != NULL ? root->left : root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				*root = *temp;
			}
		}
		else
		{
			AVLNode* temp = minValueNode(root->right);
			root->trains = temp->trains;
			root->right = deleteNode(root->right, temp->trains[0]);
		}
	}

	if (root == NULL)
	{
		return root;
	}

	// depth
	root->depth = max(depth(root->left), depth(root->right)) + 1;
	int balance = getBalance(root);

	// повернем дерево если оно не является сбалансированным

	// лево лево
	if (balance > 1 && getBalance(root->left) >= 0)
	{
		return rightRotate(root);
	}
	// лево право
	if (balance > 1 && (getBalance(root->left) < 0))
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// право право
	if (balance < -1 && getBalance(root->right) <= 0)
	{
		return leftRotate(root);
	}

	// право лево
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}



// поиск поездов отправляющихся позже
void find_train__time(AVLNode* root, int find_time, vector<Train>& Memory_trains)
{
	if (root->left != NULL)
	{
		find_train__time(root->left, find_time, Memory_trains);
	}
	for (int i = 0; i < root->trains.size(); i++)
	{
		if (root->trains[i].start_time >= find_time)
		{
			Memory_trains.push_back(root->trains[i]);
		}
	}

	if (root->right != NULL)
	{
		find_train__time(root->right, find_time, Memory_trains);
		for (int i = 0; i < root->trains.size(); i++)
		{
			if (root->trains[i].start_time >= find_time)
			{
				Memory_trains.push_back(root->trains[i]);
			}
		}
	}
}


AVLNode* find_train__point(AVLNode* root, string point, vector<Train>& Memory_trains)
{
	if (root->left != NULL)
	{
		find_train__point(root->left, point, Memory_trains);
	}
	for (int i = 0; i < root->trains.size(); i++)
	{
		if (root->trains[i].destination_point == point)
		{
			Memory_trains.push_back(root->trains[i]);
		}
	}

	if (root->right != NULL)
	{
		find_train__point(root->right, point, Memory_trains);
		for (int i = 0; i < root->trains.size(); i++)
		{
			if (root->trains[i].destination_point == point)
			{
				Memory_trains.push_back(root->trains[i]);
			}
		}
	}

	return root;
}


void showSerial(AVLNode* Elem, int level)
{
	if (Elem->left != NULL)
	{
		showSerial(Elem->left, level + 1);
	}
	for (int i = 0; i < level; i++)
	{
		cout << "      ";
	}

	
	for (auto i : Elem->trains) cout << i.serial_number << ' ';
	cout << '\n';

	if (Elem->right != NULL)
	{
		showSerial(Elem->right, level + 1);
	}
}


void show(AVLNode* Elem, int level)
{
	if (Elem->left != NULL)
	{
		show(Elem->left, level + 1);
	}
	for (int i = 0; i < level; i++)
	{
		cout << "      ";
	}

	cout << Elem->trains[0].destination_point << '\n';
	cout << '\n';

	if (Elem->right != NULL)
	{
		show(Elem->right, level + 1);
	}
}



void interface_find_trains__point(AVLNode* Root)
{
	vector<Train> Memory_trains;
	
	cout << "введите точку прибытия = ";
	string point;
	cin >> point;
	find_train__point(Root, point, Memory_trains);

	cout << "\n\n =============================\n\n";

	if (Memory_trains.empty())
	{
		cout << "НЕТ поездов отправляющихся в ваш пункт. \n";
	}
	else
	{
		for (auto i : Memory_trains) {
			cout << i.destination_point << '\n' << i.serial_number << '\n' << i.start_time << "\n\n";
		}
	}

	cout << "\n\n =============================\n\n";
	Memory_trains.clear();
}

void interface_find_trains__time(AVLNode* Root)
{
	int time;
	cout << "введите время после которого мы будем искать поезда = \n";
	cin >> time;
	vector<Train> Memory_trains;
	find_train__time(Root, time, Memory_trains);

	if (Memory_trains.empty())
	{
		cout << "НЕТ поездов отправляющихся после времени К. \n";
	}
	else
	{
		for (auto i : Memory_trains) {
			cout << i.destination_point << '\n' << i.serial_number << '\n' << i.start_time << "\n\n";
		}
	}
	Memory_trains.clear();
}

void changeNode(AVLNode* Root, Train prev_train, Train cur_train)
{
	vector<Train> Tmp;
	if (find_train__point(Root, prev_train.destination_point, Tmp) != NULL)
	{
		deleteNode(Root, prev_train);
		Root = insert(Root, cur_train);
	}
	else {
		cout << "Error: elemen doesn`t exist!\n";
	}
}



void changObjectNode(AVLNode* Root, Train prev_train, Train cur_train)
{
	vector<Train> Tmp;
	AVLNode* cur = find_train__point(Root, prev_train.destination_point, Tmp);

	if (cur != NULL)
	{

		for (int i = 0; i < cur->trains.size(); i++)
		{
			if (cur->trains[i].serial_number == cur_train.serial_number)
			{
				cur->trains[i].destination_point = cur_train.destination_point;
				cur->trains[i].serial_number = cur_train.serial_number;
				cur->trains[i].start_time = cur_train.start_time;
				break;
			}
		}
	}
	else {
		cout << "Error: elemen doesn`t exist!\n";
	}
}




void OrderReaderConsole(AVLNode* root)
{
	Train data;
	std::cout << "\nвведите пункт куда поезд приедет: ";
	std::cin >> data.destination_point;
	std::cout << "\nвведите серийный номер поезда: ";
	std::cin >> data.serial_number;
	std::cout << "\nВведите время отправления в секундах текущего дня начиная с 00:00:00 = ";
	std::cin >> data.start_time;
	std::cout << "\n";

	root = insert(root, data);
}

AVLNode* FileReader(AVLNode* root)
{
	Train data;
	std::string command = "", data_buff;
	std::ifstream in("input.txt");
	
	int count_data;
	in >> count_data;

	for (int i = 0; i < count_data; i++)
	{
		in >> data.destination_point;
		in >> data.serial_number;
		in >> data.start_time;
		root = insert(root, data);
	}

	return root;
}


void print_menu(AVLNode* Root)
{
	cout << "1 = считать с консоли по 1 поезду\n";
	cout << "2 = считать с файла по n поездов\n";
	cout << "3 = вывести дерево в консоль\n";
	cout << "4 = вставить ещё один узел(поезд)\n";
	cout << "5 = удалить узел\n";
	cout << "6 = изменить информацию об данном объекте\n";
	cout << "7 = вывод информации о поездах отправляющихся после времени К\n";
	cout << "8 = вывод информации о поездах отправляющихся в пункт N\n";
	cout << "0 = выход\n";

	int number;
	cin >> number;
	string point;
	Train deleteTrain;
	Train data_prev;
	Train data_cur;

	switch (number)
	{
	case 1:
		OrderReaderConsole(Root);

		print_menu(Root);
		break;
	case 2:
		Root = FileReader(Root);

		print_menu(Root);
		break;
	case 3:
		show(Root, 0);

		print_menu(Root);
		break;
	case 4:
		OrderReaderConsole(Root);

		print_menu(Root);
		break;
	case 5:
		cout << "введите пункт назначения через который удалим узел";
		cin >> point;
		deleteTrain.destination_point = point;
		deleteNode(Root, deleteTrain);

		print_menu(Root);
		break;
	case 6:
		cout << "введите поезд который будем удалять\n";
		std::cout << "\nвведите пункт куда поезд приедет: ";
		std::cin >> data_prev.destination_point;
		std::cout << "\nвведите серийный номер поезда: ";
		std::cin >> data_prev.serial_number;
		std::cout << "\nВведите время отправления в секундах текущего дня начиная с 00:00:00 = ";
		std::cin >> data_prev.start_time;
		std::cout << "\n";

		cout << "введите поезд которым будем заменять\n";
		std::cout << "\nвведите пункт куда поезд приедет: ";
		std::cin >> data_cur.destination_point;
		std::cout << "\nвведите серийный номер поезда: ";
		std::cin >> data_cur.serial_number;
		std::cout << "\nВведите время отправления в секундах текущего дня начиная с 00:00:00 = ";
		std::cin >> data_cur.start_time;
		std::cout << "\n";
		changObjectNode(Root, data_prev, data_cur);

		print_menu(Root);
		break;
	case 7:
		interface_find_trains__time(Root);
		break;
	case 8:
		interface_find_trains__point(Root);
		print_menu(Root);
		break;
	case 0:
		exit(0);
		break;
	default:
		break;
	}


}


int main()
{
	setlocale(LC_ALL, "Rus");
	
	Train first;
	first.destination_point = "A";
	first.serial_number = 123123;
	first.start_time = 0;
	Train second;
	second.destination_point = "B";
	second.serial_number = 321321;
	second.start_time = 2;
	Train third;
	third.destination_point = "B";
	third.serial_number = 3939393;
	third.start_time = 3;
	Train four;
	four.destination_point = "B";
	four.serial_number = 282828;
	four.start_time = 4;

	Train five;
	five.destination_point = "E";
	five.serial_number = 45454;
	five.start_time = 0;

	Train six;
	six.destination_point = "F";
	six.serial_number = 96975;
	six.start_time = 2;
	Train seven;
	seven.destination_point = "G";
	seven.serial_number = 34895;
	seven.start_time = 3;
	Train eight;
	eight.destination_point = "H";
	eight.serial_number = 2582589;
	eight.start_time = 4;



	Train newTrain;
	newTrain.destination_point = "A";
	newTrain.serial_number = 90909090;
	newTrain.start_time = 000000;



	AVLNode* Root = NULL;
	/*Root = insert(Root, first);
	Root = insert(Root, second);
	Root = insert(Root, third);
	Root = insert(Root, four);
	Root = insert(Root, five);
	Root = insert(Root, six);
	Root = insert(Root, seven);
	Root = insert(Root, eight);*/
	
	print_menu(Root);
	/*

	show(Root, 0);
	cout << "\n=======================\n";
	showSerial(Root, 0);
	cout << "\n=======================\n";

	changeNode(Root, first, newTrain);

	show(Root, 0);
	cout << "\n=======================\n";
	showSerial(Root, 0);*/

}