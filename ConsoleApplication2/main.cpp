// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Overcoat.h"
#include "Flat.h"

using namespace std;

int main() {

    cout << "hello" << endl;

   /* Задание 1
        Создать класс Overcoat(верхняя одежда)

        Реализовать перегруженные операторы :

    Проверка на равенство типов одежды(операция = = )
        Операцию присваивания одного объекта в другой(операция = )
        Сравнение по цене двух пальто одного типа(операция > )*/



    int n;
    std::cout << "Enter the number of coats: ";
    std::cin >> n;

    Overcoat* coats = new Overcoat[n];

    for (int i = 0; i < n; ++i) {
        std::cout << "\nCoat #" << (i + 1) << ":\n";
        coats[i].input();
    }

    sortDescendingByPrice(coats, n);

    std::cout << "\nSorted list (by descending price):\n";
    for (int i = 0; i < n; ++i)
        coats[i].print();

    int delIndex;
    std::cout << "\nEnter index to delete (0 - " << n - 1 << "): ";
    std::cin >> delIndex;
    removeByIndex(coats, n, delIndex);

    std::cout << "\nList after deletion:\n";
    for (int i = 0; i < n; ++i)
        coats[i].print();

    delete[] coats;

////////////////////////////////////////////////////////////////////////


    /*Задание 2
        Создать класс Flat(квартира)

        Реализовать перегруженные операторы :

    Проверка на равенство площадей квартир(операция == )
        Операцию присваивания одного объекта в другой(операция = )
        Сравнение двух квартир по цене(операция > )*/





    
    cout << "Enter the number of flats: ";
    cin >> n;

    Flat* flats = new Flat[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nFlat #" << (i + 1) << ":\n";
        flats[i].input();
    }

    sortDescendingByPrice(flats, n);

    cout << "\nFlats sorted by descending price:\n";
   
    for (int i = 0; i < n; ++i)
        flats[i].print();

    delete[] flats;
    return 0;
}