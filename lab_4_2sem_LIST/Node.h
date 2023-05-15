#pragma once
#include "Header.h"

struct Node {
    Node() = default;
    Node(int key)
    {
        this->key = key;
        this->prev = this->next = NULL;
    }
    // информация о текущем узле
    int key = 0;
    // указатели на текущий и предыдущий элемент
    Node* prev;
    Node* next;
};