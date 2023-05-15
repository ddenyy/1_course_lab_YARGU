#include "Header.h"
#include "List.h"

bool function_comporator_sum(int item)
{
    if (item < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    List lst;

    lst.push_front(10);
    lst.push_front(20);
    lst.push_front(30);
    lst.push_front(40);
    lst.push_front(50);
    lst.push_front(60);
    lst.push_front(70);
    lst.push_front(80);
    lst.push_front(-10);
    lst.push_front(20);
    lst.push_front(30);
    lst.push_front(40);
    lst.push_front(-50);
    lst.push_front(60);
    lst.push_front(70);
    lst.push_front(-80);
    lst.push_front(90);
    lst.push_front(90);

    bool(*pointerComp)(int item);
    pointerComp = function_comporator_sum;

    cout << lst.get_amout(pointerComp) << '\n';
    lst.print_list();
    lst.reverse();
    lst.print_list();
}
