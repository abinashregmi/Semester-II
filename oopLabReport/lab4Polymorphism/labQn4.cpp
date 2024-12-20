//Create a C++ program that models a simple banking system. Implement a base class Account and derived classes SavingsAccount and CheckingAccount. Use virtual functions to perform operations like deposit, withdrawal, and interest calculation.
#include <iostream>
using namespace std;
class Account {
protected:
    float balance;
public:
    Account(float initialBalance) : balance(initialBalance) {}
    virtual void deposit(float amount) {
        balance += amount;
    }
    virtual void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }
    virtual void display() const {
        cout << "Balance: $" << balance << endl;
    }
    virtual ~Account() {}
};
class SavingsAccount : public Account {
private:
    float interestRate;
public:
    SavingsAccount(float initialBalance, float rate) 
        : Account(initialBalance), interestRate(rate) {}
    void deposit(float amount) override {
        Account::deposit(amount);
        cout << "Deposited $" << amount << " to Savings Account" << endl;
    }
    void withdraw(float amount) override {
        Account::withdraw(amount);
        cout << "Withdrew $" << amount << " from Savings Account" << endl;
    }
    void applyInterest() {
        float interest = (balance * interestRate) / 100;
        deposit(interest);
        cout << "Applied interest of $" << interest << " to Savings Account" << endl;
    }
    void display() const override {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};
class CheckingAccount : public Account {
public:
    CheckingAccount(float initialBalance) : Account(initialBalance) {}
    void deposit(float amount) override {
        Account::deposit(amount);
        cout << "Deposited $" << amount << " to Checking Account" << endl;
    }
    void withdraw(float amount) override {
        Account::withdraw(amount);
        cout << "Withdrew $" << amount << " from Checking Account" << endl;
    }
    void display() const override {
        Account::display();
    }
};
int main() {
    SavingsAccount savings(1000, 5);
    CheckingAccount checking(500);
    savings.deposit(200);
    savings.withdraw(100);
    savings.applyInterest();
    savings.display();
    checking.deposit(150);
    checking.withdraw(50);
    checking.display();
    cout << "Abinash Regmi" << endl;
    return 0;
}
