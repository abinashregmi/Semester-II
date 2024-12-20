#include <iostream>
using namespace std;

class Parent {
public:
    void show() {
        cout << "Parent showing\n";
    }
};

class Base1 : public Parent {

};

class Base2 : public Parent{

}

class Derived : public Base1, public Base2 {

};

int main() {
    Derived d;
    d.show();
    return 0;
}