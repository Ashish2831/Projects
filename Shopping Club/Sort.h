#include <iostream>
using namespace std;

class ForSorting
{
    string name;
    int quantity;
    float price;

public:
    static short decide;             // Static Variable
    void setter(string, int, float); // Setter Method
    string getName();                // Getter Method For Name
    int getQuantity();               // Getter Method For Quantity
    float getPrice();                // Getter Method For Price
    bool operator<=(ForSorting);     // Operator Overloading
};

short ForSorting::decide = 0;

bool ForSorting::operator<=(ForSorting fs1)
{
    if (ForSorting::decide == 1)
        return this->getQuantity() <= fs1.getQuantity();

    else if (ForSorting::decide == 2)
        return this->getPrice() <= fs1.getPrice();

    else
        return this->getName() <= fs1.getName();
}

void ForSorting::setter(string name, int quantity, float price)
{
    this->name = name;
    this->quantity = quantity;
    this->price = price;
}

string ForSorting::getName()
{
    return this->name;
}

int ForSorting::getQuantity()
{
    return this->quantity;
}

float ForSorting::getPrice()
{
    return this->price;
}