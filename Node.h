#pragma once
#include "Header.h"

struct Node {
    Node() = default;
    Node(int key)
    {
        this->key = key;
        this->prev = this->next = NULL;
    }
    // ���������� � ������� ����
    int key = 0;
    // ��������� �� ������� � ���������� �������
    Node* prev;
    Node* next;
};