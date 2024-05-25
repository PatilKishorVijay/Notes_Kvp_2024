#include "Common.h"

class Vehicle {
protected:
    string make;
    string model;
    int year;
public:
    Vehicle(string m, string md, int y) {
        make = m;
        model = md;
        year = y;
    }

    virtual void getDetails() = 0;
};

class Car : public Vehicle {
public:

    Car(string c,string m,int yr ) :Vehicle(c,m,yr)
    {

    }
    void getDetails() {
        cout << make << " " << model << " " << year << endl;
    }
};

int main1711() {
    Vehicle* v = new Car("Toyota", "Camry", 2021);
    v->getDetails();
    delete v;
    return 0;
}