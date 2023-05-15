#pragma once
#include "Header.h"
#include "Node.h"

class List
{
public:

	List(int default_key = 0)
	{
		head_elem = last_elem = NULL;
		size_list = 0;
	}

	~List()
	{
		while (head_elem != NULL)
		{
			pop_front();
		}
	}

	// insert to begin lest
	Node* push_front(int key)
	{
		// increase size list
		size_list += 1;
		// create new node
		Node* new_node = new Node(key);
		// insert new elem in List
		new_node->next = head_elem;
		new_node->prev = nullptr;

		if (head_elem != NULL)

		{
			head_elem->prev = new_node;
		}

		if (last_elem == NULL)
		{
			last_elem = new_node;
		}
		head_elem = new_node;

		return new_node;
	}

	// insert elem to the end
	Node* push_back(int key)
	{
		// increase size list
		size_list += 1;
		Node* new_node = new Node(key);
		// insert new elem in List
		new_node->prev = last_elem;

		if (last_elem != NULL)
		{
			last_elem->next = new_node;
		}
		if (head_elem == NULL)
		{
			head_elem = new_node;
		}

		last_elem = new_node;

		return new_node;
	}

	void pop_front()
	{
		if (head_elem == NULL)
		{
			return;
		}
		Node* tmp_ptr = head_elem->next;

		if (tmp_ptr != NULL)
		{
			tmp_ptr->prev = NULL;
		}
		else
		{
			// удаляем указатель хвоста ибо один элемент в списке
			last_elem = NULL;
		}
		delete head_elem;
		head_elem = tmp_ptr;

		// decrease size list
		size_list -= 1;
	}

	void pop_back()
	{
		if (last_elem == NULL)
		{
			return;
		}

		Node* tmp_ptr = last_elem->prev;

		if (tmp_ptr != NULL)
		{
			tmp_ptr->next = NULL;
		}
		else
		{
			// удаляем указатель головы ибо один элемент в списке
			head_elem = NULL;
		}
		delete last_elem;
		last_elem = tmp_ptr;
		// decrease size list
		size_list -= 1;
	}

	// метод для получения информации об узле с номером index
	Node* getAt(int index)
	{
		Node* ptr = head_elem;
		int n = 0;

		while (n != index)
		{
			if (ptr == NULL)
			{
				return ptr;
			}
			ptr = ptr->next;
			n++;
		}
		return ptr;
	}


	Node* operator [] (int index)
	{
		return getAt(index);
	}

	Node* insert(int index, int data)
	{
		Node* right = getAt(index);

		if (right == NULL)
		{
			return push_back(data);
		}
		Node* left = right->prev;
		if (left == NULL)
		{
			return push_front(data);
		}

		// создали новый узел
		Node* ptr = new Node(data);
		// вставили узел
		ptr->prev = left;
		ptr->next = right;
		left->next = ptr;
		right->prev = ptr;

		size_list += 1;

		return ptr;
	}

	// удаление по индексу
	void earase(int index)
	{
		Node* ptr = getAt(index);
		if (ptr == NULL)
		{
			return;
		}

		if (ptr->prev == NULL)
		{
			pop_front();
			return;
		}
		if (ptr->next == NULL)
		{
			pop_back();
			return;
		}

		Node* left = ptr->prev;
		Node* right = ptr->next;

		left->next = right;
		right->prev = left;
		delete ptr;

		size_list -= 1;
	}

	void print_list()
	{
		Node* tmp = head_elem;
		while (tmp->next != NULL)
		{
			cout << tmp->key << ' ';
			tmp = tmp->next;
		}
		cout << tmp->key << '\n';
	}

	int size()
	{
		return size_list;
	}

	Node* front()
	{
		return head_elem;
	}

	Node* back()
	{
		return last_elem;
	}

	// Функция для реверсирования двусвязного списка
	void reverse()
	{
		Node* prev = NULL;
		Node* curr = head_elem;

		// обход списка
		while (curr != NULL)
		{
			// поменять местами указатели `next` и `prev` для текущего узла
			swap(curr);

			// обновить предыдущий узел перед переходом к следующему узлу
			prev = curr;

			// перейти к следующему узлу в двусвязном списке
			// (переход с использованием указателя `prev`, так как указатели `next` и `prev` поменялись местами)
			curr = curr->prev;
		}

		// обновить указатель на последний узел
		if (prev != NULL) {
			head_elem = prev;
		}
	}

	// считает сумму с условием
	int get_amout(bool(*pointerComp)(int item))
	{
		int summ = 0;
		Node* tmp = head_elem;
		while (tmp->next != NULL)
		{
			if (pointerComp(tmp->key) == true)
			{
				summ += tmp->key;
			}
			tmp = tmp->next;
		}
		if (pointerComp(tmp->key) == true)
		{
			summ += tmp->key;
		}
		return summ;
	}



private:

	Node* head_elem = NULL;
	Node* last_elem = NULL;
	int size_list = 0;


	// меняет следущий и предыдущ указатели для текущего узла
	void swap(Node* node)
	{
		Node* prev = node->prev;
		node->prev = node->next;
		node->next = prev;
	}

	

};

