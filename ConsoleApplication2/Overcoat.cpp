#include "Overcoat.h"
#include <iostream>
#include <cstring>

using namespace std;


Overcoat::Overcoat() {
    type[0] = '\0';
    price = 0.0;
}

Overcoat::Overcoat(const char* t, double p) {
    strcpy_s(type, sizeof(type), t),
    price = p;
}

void Overcoat::input() {
    std::cout << "Enter coat type: ";
    std::cin >> type;
    std::cout << "Enter price: ";
    std::cin >> price;
}

void Overcoat::print() const {
    std::cout << "Type: " << type << ", Price: " << price << std::endl;
}

double Overcoat::getPrice() const {
    return price;
}

bool Overcoat::operator==(const Overcoat& other) const {
    return strcmp(this->type, other.type) == 0;
}

Overcoat& Overcoat::operator=(const Overcoat& other) {
    if (this != &other) {
       strcpy_s(this->type, sizeof(this->type), other.type);
       this->price = other.price;
    
    }
    return *this;
}

bool Overcoat::operator>(const Overcoat& other) const {
    if (*this == other)
        return this->price > other.price;
    else {
        std::cout << "Cannot compare: different coat types." << std::endl;
        return false;
    }
}

// Sort coats in descending order by price
void sortDescendingByPrice(Overcoat* arr, int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j].getPrice() < arr[j + 1].getPrice()) {
                Overcoat temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Remove coat at a given index
void removeByIndex(Overcoat*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }

    int newSize = size - 1;
    Overcoat* newArr = new(std::nothrow) Overcoat[newSize];
    if (!newArr) {
        std::cerr << "Memory allocation failed!" << std::endl;
        return;
    }

    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (i != index) {
            newArr[j] = arr[i];
            ++j;
        }
    }

    delete[] arr;
    arr = newArr;
    size = newSize;
}