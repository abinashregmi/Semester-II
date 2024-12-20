#include <iostream>
using namespace std;
class Student {
public:
    int age;
    Student(int age) {
        this->age = age;
    }
    Student& operator++() {
        ++age; 
        return *this;
    }
    void display()  {
        cout << "Age = " << age << endl;
    }
};
int main() {
    Student s(142); 
    ++s;  
    s.display();  
    return 0;
}
