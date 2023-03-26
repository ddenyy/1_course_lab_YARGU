#include "menu.h"
#include "Api_vector.h"

// ф-ция требует выбрать пользоваля каким образом мы считываем данных
// принимает вектор объектов класса, по сути нашу базу данных
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

// ф-ция требует выбрать пользователю что он хочет сделать см.тз.лабы
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
            cout << "Текущий размер базы данных = " << DataBase.size() - 1 << '\n';
            cout << "Введите позицию (гумерация с нуля) в которую будет вставлен элемент == ";
            int position;
            cin >> position;
            cout << "введите объект в консоль следуя инструкции == " << '\n';
            print_inctruction_input_for_one_object();

            Price Cur_Object = inputOneObjectFromConsole();
            add_item(Cur_Object, position, DataBase);

            print_DataBase(DataBase);

            break;
        }
        case 5:
        {
            cout << "Текущий размер базы данных = " << DataBase.size() - 1 << '\n';
            cout << "Введите позицию (гумерация с нуля) из которой будет удален элемент == ";
            int position;
            cin >> position;

            remove_item(position, DataBase);

            print_DataBase(DataBase);

            break;
        }
        case 6:
        {
            cout << "Текущий размер базы данных = " << DataBase.size() - 1 << '\n';
            cout << "Введите позицию (гумерация с нуля) в которой будет изменен элемент == ";
            int position;
            cin >> position;
            cout << "введите объект в консоль следуя инструкции == " << '\n';
            print_inctruction_input_for_one_object();

            Price Cur_Object = inputOneObjectFromConsole();
            
            change_item(Cur_Object, position, DataBase);

            print_DataBase(DataBase);

            break;
        }
        default:
        {
            cout << "команды с = " << userChoiceInput << " таким номером нет !\n";
            break;
        }
        }

        print_inctruction_logic_prog();
        menu_swith_action(DataBase);
    }

}


void print_inctruction_input()
{
    cout << "Выберите способ ввода данных\n";
    cout << "шаблон ввода данных для класса: \n количество объектов PRICE которые будут введены \n имя объекта\n";
    cout << "срок годности В ФОРМАТЕ ДД.ММ.ГГ \n количество магазинов в которых он продаётся \n имя магазина 1 \n имя магазина 2 \n и.т.д\n";
    cout << "1 - файл \t 2 - ввод с клавиатуры \n";
    cout << "Введите число = ";
}

void print_inctruction_input_for_one_object()
{
    cout << "шаблон ввода данных для класса:\n имя объекта\n цена за 1 шт \n";
    cout << "срок годности \n количество магазинов в которых он продаётся \n имя магазина 1 \n имя магазина 2 \n и.т.д\n";
    
}


void print_inctruction_logic_prog()
{
    cout << "выберите что вы хотите сделать = \n";
    cout << "1 - Упорядочить записи по названию товара и стоимости \n";
    cout << "2 - Вывод на экран информации о товарах, имеющих срок годности больше заданного\n";
    cout << "3 - Вывод на экран информации о магазинах в которых продаётся товары с ценой выше средней\n";

    cout << "4 - добавить элемент в массив объектов\n";
    cout << "5 - удалить элемент в массиве объектов\n";
    cout << "6 - изменение элемента в массиве объектов\n";

    cout << "0 - Выход из программы\n";
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