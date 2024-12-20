//Write a program that defines an abstract base class Animal with a pure virtual function void speak(). Create two derived classes, Dog and Cat, which implement the speak() function. Use an array of Animal pointers to store instances of both Dog and Cat. Write a loop to make all animals in the array speak.
#include <iostream>
using namespace std;
class Animal {
public:
    virtual void speak() const = 0;
    virtual ~Animal() {}
};
class Dog : public Animal {
public:
    void speak() const override {
        cout << "Dog says: Woof!" << endl;
    }};
class Cat : public Animal {
public:
    void speak() const override {
        cout << "Cat says: Meow!" << endl;
    }};
int main() {
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();
    for (int i = 0; i < 2; ++i) {
        animals[i]->speak(); }
    for (int i = 0; i < 2; ++i) {
        delete animals[i];
    }
    cout << "Abinash Regmi" <<endl;		 
    return 0;
}
