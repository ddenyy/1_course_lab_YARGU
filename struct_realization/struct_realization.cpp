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
//struct Node_stack
//{
//    int info;
//    Node_stack* next = NULL;
//};
//
//// проверяет пустой ли стек
//bool empty_stack(Node_stack* Head)
//{
//    if (Head->next == NULL) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//// считаем количество элементов стека
//int size_stack(Node_stack* Head)
//{
//    // создаем буферный указатель, который побежит по всему стеку
//    Node_stack* Buffer_Node = new Node_stack;
//    Buffer_Node = Head;
//    // количество элементов в стеке
//    int count_elem = 0;
//    while (Buffer_Node->next != NULL)
//    {
//        count_elem++;
//        Buffer_Node = Buffer_Node->next;
//    }
//    /*delete Buffer_Node;*/
//    return count_elem;
//}
//
//// достаем элемент из верхушки стека
//void top_stack(Node_stack* Head)
//{
//    if (empty_stack(Head))
//    {
//        cout << "stack empty!\n";
//    }
//    else
//    {
//        cout << Head->next->info << '\n';
//    }
//}
//
//void pop_stack(Node_stack* Head)
//{
//    if (empty_stack(Head))
//    {
//        cout << "stack empty!\n";
//    }
//    else
//    {
//        Head->next = Head->next->next;
//    }
//}
//
//void push_stack(Node_stack* Head, int data)
//{
//    Node_stack* Buffer_node = new Node_stack;
//    Buffer_node->info = data;
//    Buffer_node->next = Head->next;
//    Head->next = Buffer_node;
//}
//
//
//void menu()
//{
//    cout << "1 push\n";
//    cout << "2 pop\n";
//    cout << "3 top\n";
//    cout << "4 size\n";
//    cout << "5 empty\n";
//    cout << "0 exit\n";
//
//}
//int main()
//{
//    setlocale(LC_ALL, "RUS");
//    // создали указатель на голову стека, прикрепили к ней объект который создали через new
//    Node_stack* Head_stack = new Node_stack;
//    
//    int number = 10;
//    
//    while (number != 0) {
//        // выводим меню
//        menu();
//
//        cin >> number;
//        switch (number)
//        {
//        case 1:
//        {
//            cout << "введите число которое закидываем в стек\n";
//            int data;
//            cin >> data;
//            push_stack(Head_stack, data);
//            break;
//        }
//        case 2:
//        {
//            pop_stack(Head_stack);
//            break;
//        }
//        case 3:
//        {
//            top_stack(Head_stack);
//            break;
//        }
//        case 4:
//        {
//            cout << size_stack(Head_stack);
//            break;
//        }
//        case 5:
//        {
//            if (empty_stack(Head_stack))
//            {
//                cout << "stack empty!\n";
//            }
//            else
//            {
//                cout << "stack NO empty!\n";
//            }
//            break;
//        }
//        case 0:
//        {
//            break;
//        }
//        default:
//            break;
//        }
//    }
//
//}
