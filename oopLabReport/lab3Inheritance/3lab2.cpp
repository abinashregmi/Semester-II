#include <iostream>
using namespace std;

class Marks {
protected:
    int subject1, subject2, subject3;
public:
    void getMarks() {
        cout << "Enter the marks for Discrete Structure: ";
        cin >> subject1;
        cout << "Enter the marks for Mathematics-II: ";
        cin >> subject2;
        cout << "Enter the marks for Microprocessor: ";
        cin >> subject3;
    }
};

class Total : public Marks {
protected:
    int totalMarks;
public:
    void calculateTotal() {
        totalMarks = subject1 + subject2 + subject3;
    }
};

class Percentage : public Total {
public:
    void calculatePercentage() {
        float percentage = (totalMarks / 3.0);
        cout << "The percentage of the honourable failed student is " << percentage << "%" << endl;
    }
};

int main() {
    Percentage student;
    student.getMarks();
    student.calculateTotal();
    student.calculatePercentage();
    return 0;
}