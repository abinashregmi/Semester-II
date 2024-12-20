#include <iostream>
using namespace std;

class Student {
private:
    string student_name;
    int student_age;
    int student_roll;

public:
    void setName(string name) {
        student_name = name;
    }

    void setAge(int age) {
        student_age = age;
    }

    void setRoll(int roll) {
        student_roll = roll;
    }

    string getName() {
        return student_name;
    }

    int getAge() {
        return student_age;
    }

    int getRoll() {
        return student_roll;
    }
};

int main() {
    string name;
    int age;
    int rollno;

    Student S;

    cout << "Enter the name of student: ";
    cin >> name;

    cout << "Enter the age of student: ";
    cin >> age;

    cout << "Enter the roll no of student: ";
    cin >> rollno;

    S.setName(name);
    S.setAge(age);
    S.setRoll(rollno);

    cout << "Student name: " << S.getName() << endl;
    cout << "Student age: " << S.getAge() << endl;
    cout << "Student roll no: " << S.getRoll() << endl;

    return 0;
}