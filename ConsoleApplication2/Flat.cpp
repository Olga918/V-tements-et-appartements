#define _CRT_SECURE_NO_WARNINGS
#include "Flat.h"
#include <iostream>

using namespace std;
Flat::Flat() {
    area = 0.0;
    price = 0.0;
}

Flat::Flat(double a, double p) {
    area = a;
    price = p;
}

void Flat::input() {
    cout << "Enter area: ";
    cin >> area;
    cout << "Enter price: ";
    cin >> price;
}

void Flat::print() const {
    cout << "Area: " << area << ", Price: " << price << endl;
}

double Flat::getPrice() const {
    return price;
}

bool Flat::operator==(const Flat& other) const {
    return this->area == other.area;
}

Flat& Flat::operator=(const Flat& other) {
    if (this != &other) {
        this->area = other.area;
        this->price = other.price;
    }
    return *this;
}

bool Flat::operator>(const Flat& other) const {
    return this->price > other.price;
}

void sortDescendingByPrice(Flat* arr, int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j].getPrice() < arr[j + 1].getPrice()) {
                Flat temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}