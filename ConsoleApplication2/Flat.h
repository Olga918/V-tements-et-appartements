#pragma once
class Flat {
private:
    double area;   // Площадь квартиры
    double price;  // Цена квартиры

public:
    Flat();                     // Конструктор по умолчанию
    Flat(double a, double p);   // Конструктор с параметрами

    void input();               // Ввод
    void print() const;         // Вывод

    double getPrice() const;    // Получить цену

    bool operator==(const Flat& other) const;   // Сравнение по площади
    Flat& operator=(const Flat& other);         // Присваивание
    bool operator>(const Flat& other) const;    // Сравнение по цене
};

// Объявление сортировки
void sortDescendingByPrice(Flat* arr, int size);