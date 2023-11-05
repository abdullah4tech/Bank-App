#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Account {
public:
    string accountHolder;
    int accountNumber;
    double accountBalance;


    Account(string accHolder, int accNo, double balance)
        : accountHolder(accHolder),
          accountNumber(accNo),
          accountBalance(balance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return accountBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            accountBalance += amount;
            cout << "Deposited $" << amount << " into account #" << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= accountBalance) {
            accountBalance -= amount;
            cout << "Withdrawn $" << amount << " from account #" << accountNumber << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }
};

class Bank {
private:
    vector<Account> accounts;
    int nextAccountNumber = 1;

public:
    void createAccount(string accountHolder, double initialBalance) {
        Account account(accountHolder, nextAccountNumber, initialBalance);
        accounts.push_back(account);
        cout << "Account created with number #" << nextAccountNumber << endl;
        nextAccountNumber++;
    }

    void displayAccountDetails(int accountNumber) {
        for (const Account& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                cout << "Account Number: " << account.getAccountNumber() << endl;
                cout << "Account Holder: " << account.accountHolder << endl; // Display account holder's name
                cout << "Balance: $" << account.getBalance() << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void deposit(int accountNumber, double amount) {
        for (Account& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.deposit(amount);
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void withdraw(int accountNumber, double amount) {
        for (Account& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.withdraw(amount);
                return;
            }
        }
        cout << "Account not found." << endl;
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\nBanking System Menu" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            string accountHolder;
            double initialBalance;
            cout << "Enter account holder's name: ";
            cin.ignore();
            getline(cin, accountHolder);
            cout << "Enter initial balance: $";
            cin >> initialBalance;
            bank.createAccount(accountHolder, initialBalance);
            break;
        }
        case 2: {
            system("cls");
            int accountNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter deposit amount: $";
            cin >> amount;
            bank.deposit(accountNumber, amount);
            break;
        }
        case 3: {
            system("cls");
            int accountNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter withdrawal amount: $";
            cin >> amount;
            bank.withdraw(accountNumber, amount);
            break;
        }
        case 4: {
            system("cls");
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            bank.displayAccountDetails(accountNumber);
            break;
        }
        case 0:
            cout << "Exiting the banking system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
