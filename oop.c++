#include <iostream>
using namespace std;

class ATM {
private:
    int pin = 2324;
    double balance = 50000;

public:
    void checkPin() {
        int enteredPin;
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            menu();
        } else {
            cout << "Incorrect PIN!\n";
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\n===== ATM MENU =====\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    cout << "Thank you for using ATM!\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 4);
    }

    void checkBalance() {
        cout << "Current Balance: ₹" << balance << endl;
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful!\n";
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        }
    }
};

int main() {
    ATM atm;
    atm.checkPin();
    return 0;
}