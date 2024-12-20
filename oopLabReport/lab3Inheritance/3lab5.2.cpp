#include <iostream>
using namespace std;

class Base1 {
public:
    void show() {
        cout << "Base1 show() function" << endl;
    }
};

class Base2 {
public:
    void show() {
        cout << "Base2 show() function" << endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    void show() {
        cout << "Derived show() function" << endl;
        Base1::show();
        Base2::show();
    }
};

int main() {
    Derived d;
    d.Base1::show();
    d.Base2::show();
    d.show();
    return 0;
}