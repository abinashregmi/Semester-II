#include <iostream>
using namespace std;

class Student
{
    public:
    int *age;
    Student()
    {
        age = new int;
        *age = 0;
    }
    void setAge(int age)
    {
        *(this->age) = age;
    }
    int getAge()
    {
        return *age;
    }

};

int main()
{
    Student s1;
    s1.setAge(20);
    Student s2 = s1;
    cout << s1.getAge() << endl; 
    cout << s2.getAge() << endl;
    cout << "After modifying s2 age" << endl;
    s2.setAge(40);
    cout << s1.getAge() << endl;
    cout << s2.getAge() << endl;
    return 0;
}