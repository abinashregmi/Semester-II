#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    string depositer_name;
    string account_number;
    static string account_type;
    double account_balance;

public:
    Bank(string name, string acc_number, double initial_balance) {
        depositer_name = name;
        account_number = acc_number;
        account_balance = initial_balance;
    }

    void withdrawAmount(double amount) {
        if (amount > 0 && account_balance >= amount) {
            account_balance -= amount;
            cout << "Withdrawing: " << amount << " Remaining balance: " << account_balance << endl;
        } else {
            cout << "Withdrawal unsuccessful. Insufficient balance." << endl;
        }
    }

    void depositAmount(double amount) {
        if (amount > 0) {
            account_balance += amount;
            cout << "Deposited: " << amount << " New balance: " << account_balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    friend void displayDetails(Bank& acc);

    static void modifyAccountType(const string& new_type) {
        account_type = new_type;
    }
};

string Bank::account_type = "Savings";

void displayDetails(Bank& acc) {
    cout << "Depositor Name: " << acc.depositer_name << endl;
    cout << "Account Number: " << acc.account_number << endl;
    cout << "Account Type: " << Bank::account_type << endl;
    cout << "Account Balance: " << acc.account_balance << endl;
}

int main() {
    Bank acc1("Milan", "A50706754", 30000);

    acc1.depositAmount(2000);
    acc1.withdrawAmount(8000);

    Bank::modifyAccountType("Saving");

    displayDetails(acc1);

    return 0;
}