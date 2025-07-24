#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    string name;
    long long accnumber;
    char type[10];
    long long tot = 0; // Total balance

public:
    void setvalue() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Account number: ";
        cin >> accnumber;
        cout << "Enter Account type: ";
        cin >> type;
        cout << "Enter Initial Balance: ";
        cin >> tot; // Set initial balance
    }

    void showdata() {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accnumber << endl;
        cout << "Account type: " << type << endl;
        cout << "Balance: " << tot << endl;
    }

    void deposit() {
        long long amount;
        cout << "\nEnter amount to be Deposited: ";
        cin >> amount;
        if (amount > 0) {
            tot += amount; // Update total balance
            cout << "Amount Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void showbal() {
        cout << "\nTotal balance is: " << tot << endl; // Show current balance
    }

    void withdrawl() {
        long long amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > 0 && amount <= tot) {
            tot -= amount; // Update total balance
            cout << "Amount Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }
};

int main() {
    Bank b;
    int choice;

    while (true) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~WELCOME~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~\n\n";
        cout << "Enter Your Choice\n";
        cout << "\t1. Enter name, Account number, Account type\n";
        cout << "\t2. Balance Enquiry\n";
        cout << "\t3. Deposit Money\n";
        cout << "\t4. Show Total balance\n";
        cout << "\t5. Withdraw Money\n";
        cout << "\t6. Cancel\n";
        cin >> choice;

        switch (choice) {
        case 1:
            b.setvalue();
            break;
        case 2:
            b.showdata();
            break;
        case 3:
            b.deposit();
            break;
        case 4:
            b.showbal();
            break;
        case 5:
            b.withdrawl();
            break;
        case 6:
            exit(0); // Normal exit
        default:
            cout << "\nInvalid choice\n";
        }
    }
}
