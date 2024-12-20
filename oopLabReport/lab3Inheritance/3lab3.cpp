#include <iostream>
using namespace std;

class ClassB;  

class ClassA {
private:
    int valueA;
public:
    ClassA(int a) : valueA(a) {}
    void display() {
        cout << "Marks of Rohan: " << valueA << endl;
    }
    friend void exchangeValues(ClassA &a, ClassB &b);
};

class ClassB {
private:
    int valueB;
public:
    ClassB(int b) : valueB(b) {}
    void display() {
        cout << "Marks of Abinash: " << valueB << endl;
    }
    friend void exchangeValues(ClassA &a, ClassB &b);
};

void exchangeValues(ClassA &a, ClassB &b) {
    int temp = a.valueA;
    a.valueA = b.valueB;
    b.valueB = temp;
}

int main() {
    ClassA objA(38);
    ClassB objB(0);

    cout << "Enter the marks of Rohan STATISTIC-I: " <<endl;
    objA.display();
    objB.display();

    exchangeValues(objA, objB);

    cout << "After exchanging marks of Rohan statistics with Abinash: " << endl;
    objA.display();
    objB.display();

    return 0;
}