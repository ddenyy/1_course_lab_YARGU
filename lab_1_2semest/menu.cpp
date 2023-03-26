#include "menu.h"
#include "Api_vector.h"

// �-��� ������� ������� ���������� ����� ������� �� ��������� ������
// ��������� ������ �������� ������, �� ���� ���� ���� ������
void menu_swith_input_Data(vector<Price>& DataBase)
{
    int userChoiceInput;
    cin >> userChoiceInput;
    switch (userChoiceInput)
    {
    case 1:
    {
        DataBase = inputFromFile("input.txt");
        break;
    }
    case 2:
    {
        DataBase = inputFromConsole();
        break;
    }
    default:
    {
        break;
    }
    }
}

// �-��� ������� ������� ������������ ��� �� ����� ������� ��.��.����
void menu_swith_action(vector<Price>& DataBase)
{
   
    
    while (true)
    {
        int userChoiceInput;
        cin >> userChoiceInput;
        if (userChoiceInput == 0)
        {
            exit(0);
        }

        switch (userChoiceInput)
        {
        case 1:
        {
            realize_fist_task(DataBase);
            break;
        }
        case 2:
        {
            realize_second_task(DataBase);
            break;
        }
        case 3:
        {
            realize_third_task(DataBase);
            break;
        }
        case 4:
        {
            cout << "������� ������ ���� ������ = " << DataBase.size() - 1 << '\n';
            cout << "������� ������� (��������� � ����) � ������� ����� �������� ������� == ";
            int position;
            cin >> position;
            cout << "������� ������ � ������� ������ ���������� == " << '\n';
            print_inctruction_input_for_one_object();

            Price Cur_Object = inputOneObjectFromConsole();
            add_item(Cur_Object, position, DataBase);

            print_DataBase(DataBase);

            break;
        }
        case 5:
        {
            cout << "������� ������ ���� ������ = " << DataBase.size() - 1 << '\n';
            cout << "������� ������� (��������� � ����) �� ������� ����� ������ ������� == ";
            int position;
            cin >> position;

            remove_item(position, DataBase);

            print_DataBase(DataBase);

            break;
        }
        case 6:
        {
            cout << "������� ������ ���� ������ = " << DataBase.size() - 1 << '\n';
            cout << "������� ������� (��������� � ����) � ������� ����� ������� ������� == ";
            int position;
            cin >> position;
            cout << "������� ������ � ������� ������ ���������� == " << '\n';
            print_inctruction_input_for_one_object();

            Price Cur_Object = inputOneObjectFromConsole();
            
            change_item(Cur_Object, position, DataBase);

            print_DataBase(DataBase);

            break;
        }
        default:
        {
            cout << "������� � = " << userChoiceInput << " ����� ������� ��� !\n";
            break;
        }
        }

        print_inctruction_logic_prog();
        menu_swith_action(DataBase);
    }

}


void print_inctruction_input()
{
    cout << "�������� ������ ����� ������\n";
    cout << "������ ����� ������ ��� ������: \n ���������� �������� PRICE ������� ����� ������� \n ��� �������\n";
    cout << "���� �������� � ������� ��.��.�� \n ���������� ��������� � ������� �� �������� \n ��� �������� 1 \n ��� �������� 2 \n �.�.�\n";
    cout << "1 - ���� \t 2 - ���� � ���������� \n";
    cout << "������� ����� = ";
}

void print_inctruction_input_for_one_object()
{
    cout << "������ ����� ������ ��� ������:\n ��� �������\n ���� �� 1 �� \n";
    cout << "���� �������� \n ���������� ��������� � ������� �� �������� \n ��� �������� 1 \n ��� �������� 2 \n �.�.�\n";
    
}


void print_inctruction_logic_prog()
{
    cout << "�������� ��� �� ������ ������� = \n";
    cout << "1 - ����������� ������ �� �������� ������ � ��������� \n";
    cout << "2 - ����� �� ����� ���������� � �������, ������� ���� �������� ������ ���������\n";
    cout << "3 - ����� �� ����� ���������� � ��������� � ������� �������� ������ � ����� ���� �������\n";

    cout << "4 - �������� ������� � ������ ��������\n";
    cout << "5 - ������� ������� � ������� ��������\n";
    cout << "6 - ��������� �������� � ������� ��������\n";

    cout << "0 - ����� �� ���������\n";
}

void print_DataBase(vector<Price>& DataBase)
{
    cout << "\n\n\n";
    for (size_t i = 0; i < DataBase.size(); i++)
    {
        DataBase[i].printAllInfo();
        cout << '\n';
    }
}