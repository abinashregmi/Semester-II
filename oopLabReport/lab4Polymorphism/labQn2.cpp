//Create an abstract base class Vehicle with a pure virtual function void start(). Derive two classes, Car and Motorcycle, from Vehicle. Implement the start() function differently in each derived class. Write a program to create objects of both Car and Motorcycle and call their start() functions.
#include <iostream>
using namespace std;
class Vehicle {
public:
    virtual void start() const = 0; // Pure virtual function
};
class Car : public Vehicle {
public:
    void start() const override {
        cout << "Car is starting with a roar!" << endl;
    }
};
class Motorcycle : public Vehicle {
public:
    void start() const override {
        cout << "Motorcycle is starting with a rev!" << endl;
    }
};
int main() {
    Car car;
    Motorcycle motorcycle;
    car.start();
    motorcycle.start();
    cout << "Abinash Regmi" << endl;
    return 0;
}	

