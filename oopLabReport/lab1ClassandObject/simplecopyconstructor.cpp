#include <iostream>
using namespace std;

class Student
{
    public:
        int age;
        Student(int age)
        {   
            this->age = age;
        }
        Student(Student& s)
        {
            age = 80;
        }

};

int main()
{
    Student s1(30);
    Student s2 = s1;
    cout << s1.age << endl;
    cout << s2.age << endl;
    return 0;
}
