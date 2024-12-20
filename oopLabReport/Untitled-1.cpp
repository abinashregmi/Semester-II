#include <iostream> //This lets us use tools for showing messages and getting user input
#include <cstring> //This helps us work with text (like names)
#include <fstream> //This helps us read from and write to files
using namespace std; //This makes it easier to use common tools like cout and cin

/*
This is a class that represents an employee.
Each employee has an Id, a name, and a salary.
*/
class Emp {
    int eid;    // The emplyee's ID number
    char name[20];  // The employee's name (up to 19 letters)
    float basic;    // The employee's salary

public:
    //  This is a special function that sets up an employee with default values
    Emp()  
        : eid(0), basic(0.0) {
        strcpy(name, "Not Given"); // Set the name to "Not Given" if no name is provided
    }

    //  This is a special function that sets up an employee with specific values
    Emp(int d, const char *nm, float bs) // 
        : eid(d), basic(bs) {
        strcpy(name, nm); // Set the employee's name to the one given
    }

    // This function shows the employee's details
    void display() const {
        cout << "\n***************";
        cout << "\nEmployee Id : " << eid; // Show the employee's ID
        cout << "\nName : " << name;    //  Show the employee's name
        cout << "\nSalary : " << basic; // Show the employee's salary
        cout << "\n***************";
    }

    // These functions let us get and change the employee's details
    int getid() const { //  Get the employee's ID
        return eid;
    }

    const char *getname() const {   //  Get the employee's name
        return name;
    }

    float getbasic() const {    // Get the employee's salary
        return basic;
    }

    void setid(int d) { //  Change the employee's ID
        eid = d;
    }

    void setname(const char *nm) {  //  Change the employee's name
        strcpy(name, nm);
    }

    void setbasic(float bs) {   //  Change the employee's salary
        basic = bs;
    }
}; // End of Emp class

/*
This is a class that represent a "node" in a list.
Each node holds one employee and a link to the next node.
*/
class Node {
    Emp data;   // The employee stored in this node
    Node *next; // A link to the next node in the list 

public:
    // This special function sets up a node with an employee
    Node(const Emp& d) : data(d), next(nullptr) {}

    // These functions let us get and charge the employee data and the link to the next node
    Emp getdata() const {   //  Get the employee data from this node
        return data;    
    }

    Node *getnext() const { // Get the link to the next node
        return next;
    }

    void setdata(const Emp& d) {    // Change the employee data in this node
        data = d;
    }

    void setnext(Node *n) { // Change the link to the next node
        next = n;
    }
}; // End of the next node

/*
This is a class that represents a company with a list of employees.
*/
class Company {
    Node *start;    // The first employee in the list 

    //This function saves all employees to a file
    void saveToFile() const {
        ofstream writeFile("employee1.txt");    // Open the file to write data
        if (writeFile.is_open()) {  // Check if the file is opened correctly 
            Node *current = start;  // Start from the first employee
            while (current) {   // Traverse(Go) through each employee
            // Write the employee's ID, name, and salary to the file
                writeFile << current->getdata().getid() << " "
                          << current->getdata().getname() << " "
                          << current->getdata().getbasic() << endl;
                current = current->getnext();   // Move to the next node
            }
            writeFile.close();  //  Close the file after writing
        } else {
            cerr << "Unable to open file for writing!" << endl;     //  Show an error if the file didn't open
        }
    }

    //This function loads employees from a file
    void loadFromFile() {
        ifstream readFile("employee1.txt"); //  Open the file to read data
        if (readFile.is_open()) {   // Check if the file is opened correctly 
            int id;
            char name[20];
            float basic;
            while (readFile >> id >> name >> basic) {   //  Read employee data from the file
                Emp e(id, name, basic); //  Create an employee with the read data
                Node *newNode = new Node(e);    //  Create a new node with this employee 
                newNode->setnext(start);    // Link the new node to the start of the list
                start = newNode;    // Update the start to the new node
            }
            readFile.close();   //  Close the file after reading
        } else {
            cerr << "Unable to open file for reading!" << endl; // Show an error if the file didn't open
        }
    }

public:
    //  This special function sets up a company and loads employees from a file 
    Company() : start(nullptr) {
        loadFromFile(); // Load employee data when creating the Company object
    }

    // This function adds a new employee to the list 
    ~Company() {
        while (start) { //  Go through each node (employee) in the list
            Node *temp = start; //  Save the current node
            start = start->getnext();   // Move to the next code
            delete temp;    //  Delete the saved node
        }
    }

    // This function adds a new employee to the list
    void addemp(const Emp& e) {
        Node *temp = new Node(e);   // Create a new node with the employee
        temp->setnext(start);   // Link the new node to the start of the list
        start = temp;   //  Update the start to the new node
        saveToFile(); //    Save the updated list to the file
    }

    //  This function removes an employee by their ID
    void removeempById(int id) {
        Node *p = start;    //  Start from the first employee
        Node *prev = nullptr;   // Keep track of the previous employee
        while (p != nullptr && p->getdata().getid() != id) {    // Find the employee with the matching ID
            prev = p;   // Update the previous employee
            p = p->getnext();   //  Move to the next employee
        }

        if (p != nullptr) { // If the employee was found
            if (prev != nullptr) {  // If the employee is not the first one 
                prev->setnext(p->getnext());    // Skip the employee to remove it
            } else {
                start = p->getnext();   // Update the start if the employee to remove is the first one
            }
            delete p;   // Delete the employee
            saveToFile();   // Save the updated list to file
        } else {
            cout << "Employee with ID " << id << " not found!" << endl; // Show a message if the employee was not found
        }
    }

    // This function edits an employee's details by their ID
    void editiEmp(int id) {
        Node *p = start;    // Start from the first employee
        while (p != nullptr && p->getdata().getid() != id) {    // Find the employee with the matching ID
            p = p->getnext();   // Move to the next employee
        }

        if (p != nullptr) { // If the employee was found
            Emp updatedEmp; // Create a new employee object for the updated details
            int newId;
            char newName[20];
            float newBasic;
            cout << "\nEnter new details for employee ID " << id << ": ";
            cout << "\nNew ID: ";
            cin >> newId;
            cout << "New Name: ";
            cin.ignore(); // Ignore leftover newline
            cin.getline(newName, 20);   // Get the new name
            cout << "New Salary: ";
            cin >> newBasic;

            updatedEmp.setid(newId);    // Set the new ID
            updatedEmp.setname(newName);    // Set the new name
            updatedEmp.setbasic(newBasic);  // Set the new salary
            p->setdata(updatedEmp); // Update the node with the new employee data
            saveToFile();   // Save the updated list to the file
        } else {
            cout << "Employee with ID " << id << " not found!" << endl; //  Show a message if the employee was not found
        }
    }

    //Search for an employee by ID
    void searchEmpById(int id) const {
        Node *p = start; // Pointer to traverse the list
        while (p != nullptr && p->getdata().getid() != id) {    // Find the node with matching ID
            p = p->getnext();   //  Move to next code
        }

        if (p != nullptr) { //  If node is found
            p->getdata().display();// Display employee data
        } else {
            cout << "Employee with ID " << id << " not found!" << endl; //  Error message if ID is not found
        }
    }

    //  This function shows all employees in the list
    void DisplayallEmp() const {
        if (start == nullptr) { // If there are no employees
            cout << "\nNo employee data available." << endl;    // Show a message saying there are no employees
            return; //  Stop the function
        }

        Node *p = start;    // Start from the first employee
        while (p != nullptr) {  //  Go through each employee
            p->getdata().display(); // Show the employee's details
            p = p->getnext();   //  Move to the next Employee
        }
    }
}; // End of the Company class

// This is where program starts running
int main() {
    int ch = 0; //  A number to keep track of what the user wants to do
    Company lt; // Create a Company object to manage employees

    //  Keep showing the menu until the user wants to exit
    while (ch != 6) {   
        cout << "\n\n*********************************************";
        cout << "\n\t1. Add Employee."; //  Option to add a new employee
        cout << "\n\t2. Display Employees.";    // Option to show all employees
        cout << "\n\t3. Search By ID."; // Option to find an employee by ID
        cout << "\n\t4. Delete By ID."; // Option to remove an employee by ID
        cout << "\n\t5. Edit Employee Data.";   // Option to change an employee's details
        cout << "\n\t6. Exit";  // Option to stop the program
        cout << "\n*********************************************\n\n";
        cout << "\n\tEnter your choice: ";
        cin >> ch;  //  Get the user's choice

        // Do what the user wants based on their choice
        switch (ch) {
            case 1: {   //  If the user wants to add an employee
                int id;
                char name[20];
                float bs;
                cout << "\nEnter the ID: ";
                cin >> id;
                cout << "Enter the name: ";
                cin.ignore();   // Ignore leftover newline
                cin.getline(name, 20);  // Get the employee's name
                cout << "Enter the Salary: ";
                cin >> bs;
                Emp e1(id, name, bs);   // Create an employee with the given details
                lt.addemp(e1);  // Add the employee to the company
                break;
            }
            case 2: //  If the user wants to show all employees
                lt.DisplayallEmp();
                break;
            case 3: {   //  If the user wants to find an employee by ID
                int id;
                cout << "\nEnter the ID to search: ";
                cin >> id;
                lt.searchEmpById(id);   // Find and show the employee
                break;
            }
            case 4: {   // If the user wants to remove an employee by ID
                int id;
                cout << "\nEnter the ID to delete: ";
                cin >> id;
                lt.removeempById(id);   // Remove employee
                break;
            }
            case 5: {   //  If the user wants to change an employee's details
                int id;
                cout << "\nEnter the ID to edit: ";
                cin >> id;
                lt.editiEmp(id);    //Edit the employee's details
                break;
            }
            case 6: //  If the user wants to exit
                cout << "\nEnding the program." << endl;
                break;
            default:    // If the user enters an invalid option
                cout << "\nInvalid choice, please try again." << endl;
                break;
        }
    }

    return 0;   //  End of the program
}
