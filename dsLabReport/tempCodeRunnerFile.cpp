#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Emp {
    int eid;
    char name[20];
    float basic;

public:
    Emp() // Default constructor
        : eid(0), basic(0.0) {
        strcpy(name, "Not Given");
    }

    Emp(int d, const char *nm, float bs) // Parameterized constructor
        : eid(d), basic(bs) {
        strcpy(name, nm);
    }

    void display() const {
        cout << "\n******";
        cout << "\nEmployee Id : " << eid;
        cout << "\nName : " << name;
        cout << "\nSalary : " << basic;
        cout << "\n******";
    }

    int getid() const {
        return eid;
    }

    const char *getname() const {
        return name;
    }

    float getbasic() const {
        return basic;
    }

    void setid(int d) {
        eid = d;
    }

    void setname(const char *nm) {
        strcpy(name, nm);
    }

    void setbasic(float bs) {
        basic = bs;
    }
}; // emp class end

class Node {
    Emp data;
    Node *next;

public:
    Node(const Emp& d) : data(d), next(nullptr) {}

    Emp getdata() const {
        return data;
    }

    Node *getnext() const {
        return next;
    }

    void setdata(const Emp& d) {
        data = d;
    }

    void setnext(Node *n) {
        next = n;
    }
}; // node class end

class Company {
    Node *start;

public:
    Company() : start(nullptr) {}

    ~Company() {
        while (start) {
            Node *temp = start;
            start = start->getnext();
            delete temp;
        }
    }

    void addemp(const Emp& e) {
        Node *temp = new Node(e);
        temp->setnext(start);
        start = temp;

        ofstream writeFile("employee1.txt", ios::app);
        if (writeFile.is_open()) {
            writeFile << e.getid() << " " 
                      << e.getname() << " " 
                      << e.getbasic() << endl;
            writeFile.close();
        } else {
            cerr << "Unable to open file for writing!" << endl;
        }
    }

    void removeempById(int id) {
        Node *p = start;
        Node *prev = nullptr;
        while (p != nullptr && p->getdata().getid() != id) {
            prev = p;
            p = p->getnext();
        }

        if (p != nullptr) {
            if (prev != nullptr) {
                prev->setnext(p->getnext());
            } else {
                start = p->getnext();
            }
            delete p;

            // Rewrite the file without the removed employee
            ofstream tempFile("temp.txt");
            if (tempFile.is_open()) {
                Node *current = start;
                while (current) {
                    tempFile << current->getdata().getid() << " "
                            << current->getdata().getname() << " "
                            << current->getdata().getbasic() << endl;
                    current = current->getnext();
                }
                tempFile.close();
                remove("employee1.txt");
                rename("temp.txt", "employee1.txt");
            } else {
                cerr << "Unable to open file for writing!" << endl;
            }
        } else {
            cout << "Employee with ID " << id << " not found!" << endl;
        }
    }

    void editiEmp(int id) {
        Node *p = start;
        while (p != nullptr && p->getdata().getid() != id) {
            p = p->getnext();
        }

        if (p != nullptr) {
            Emp updatedEmp;
            int newId;
            char newName[20];
            float newBasic;
            cout << "\nEnter new details for employee ID " << id << ": ";
            cout << "\nNew ID: ";
            cin >> newId;
            cout << "New Name: ";
            cin.ignore();
            cin.getline(newName, 20);
            cout << "New Salary: ";
            cin >> newBasic;

            updatedEmp.setid(newId);
            updatedEmp.setname(newName);
            updatedEmp.setbasic(newBasic);
            p->setdata(updatedEmp);

            // Rewrite the file with updated employee data
            ofstream tempFile("temp.txt");
            if (tempFile.is_open()) {
                Node *current = start;
                while (current) {
                    tempFile << current->getdata().getid() << " "
                            << current->getdata().getname() << " "
                            << current->getdata().getbasic() << endl;
                    current = current->getnext();
                }
                tempFile.close();
                remove("employee1.txt");
                rename("temp.txt", "employee1.txt");
            } else {
                cerr << "Unable to open file for writing!" << endl;
            }
        } else {
            cout << "Employee with ID " << id << " not found!" << endl;
        }
    }

    void searchEmpById(int id) const {
        Node *p = start;
        while (p != nullptr && p->getdata().getid() != id) {
            p = p->getnext();
        }

        if (p != nullptr) {
            p->getdata().display();
        } else {
            cout << "Employee with ID " << id << " not found!" << endl;
        }
    }

    void DisplayallEmp() const {
        if (start == nullptr) {
            cout << "\nNo employee data available." << endl;
            return;
        }

        Node *p = start;
        while (p != nullptr) {
            p->getdata().display();
            p = p->getnext();
        }
    }
}; // Company class end

int main() {
    int ch = 0;
    Company lt;

    while (ch != 6) {
        cout << "\n\n*****";
        cout << "\n\t1. Add Employee.";
        cout << "\n\t2. Display Employees.";
        cout << "\n\t3. Search By ID.";
        cout << "\n\t4. Delete By ID.";
        cout << "\n\t5. Edit Employee Data.";
        cout << "\n\t6. Exit";
        cout << "\n*****\n\n";
        cout << "\n\tEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                int id;
                char name[20];
                float bs;
                cout << "\nEnter the ID: ";
                cin >> id;
                cout << "Enter the name: ";
                cin.ignore();
                cin.getline(name, 20);
                cout << "Enter the Salary: ";
                cin >> bs;
                Emp e1(id, name, bs);
                lt.addemp(e1);
                break;
            }
            case 2:
                lt.DisplayallEmp();
                break;
            case 3: {
                int id;
                cout << "\nEnter the ID 
