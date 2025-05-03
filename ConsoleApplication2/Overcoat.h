#pragma once

class Overcoat {
private:
    char type[20];
    double price;

public:
    Overcoat();
    Overcoat(const char* t, double p);

    void input();
    void print() const;

    double getPrice() const;

    bool operator==(const Overcoat& other) const;
    Overcoat& operator=(const Overcoat& other);
    bool operator>(const Overcoat& other) const;
};

void sortDescendingByPrice(Overcoat* arr, int size);
void removeByIndex(Overcoat*& arr, int& size, int index);
