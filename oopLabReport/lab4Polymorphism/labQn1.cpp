//Write a C++ program that demonstrates the concept of polymorphism using virtual functions. Create a base class Shape with a virtual function area(). Create two derived classes, Circle and Rectangle, each with their own implementation of the area() function. Calculate and display the area of different shapes using polymorphism.
#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
    virtual float area() const = 0; // Pure virtual function
};
class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}

    float area() const override {
        return M_PI * radius * radius;
    }
};
class Rectangle : public Shape {
private:
    float width;
    float height;
public:
    Rectangle(float w, float h) : width(w), height(h) {}
    float area() const override {
        return width * height;
    }
};
void displayArea(const Shape &shape) {
    cout << "Area: " << shape.area() << endl;
}
int main() {
    Circle circle(5.0); 
    Rectangle rectangle(4.0, 6.0); 
    displayArea(circle);
    displayArea(rectangle);
    cout << "Abinash Regmi" << endl;
    return 0;
}
