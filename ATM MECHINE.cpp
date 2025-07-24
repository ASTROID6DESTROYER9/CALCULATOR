#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User {
protected:
    string username;
    string pin;
    float balance;

public:
    User(string uname, string upin, float ubalance) {
        username = uname;
        pin = upin;
        balance = ubalance;
    }

    bool login(string uname, string upin) {
        return username == uname && pin == upin;
    }

    virtual void showMenu() = 0;

    virtual void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid amount." << endl;
        }
    }

    virtual void withdraw(float amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    float getBalance() {
        return balance;
    }
};

class ATM : public User {
public:
    ATM(string uname, string upin, float ubalance) : User(uname, upin, ubalance) {}

    void showMenu() override {
        int choice;
        float amount;

        do {
            cout << "\n=== ATM Menu ===" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Your balance is: " << getBalance() << endl;
                    break;
                case 2:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    deposit(amount);
                    break;
                case 3:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    withdraw(amount);
                    break;
                case 4:
                    cout << "Thank you for using the ATM!" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (choice != 4);
    }
};

int main() {
    string uname, upin;
    cout << "     Welcome to ATM      " << endl;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter PIN: ";
    cin >> upin;

    ATM user1("hammad", "1234", 1000.0);

    if (user1.login(uname, upin)) {
        user1.showMenu();
    } else {
        cout << "Login failed. Invalid username or PIN." << endl;
    }

    return 0;
}
