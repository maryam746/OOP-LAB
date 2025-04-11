
#include <iostream>

using namespace std;

class Account;

class Manager {
public:
    void deposit(Account& acc, double amount);
    void withdraw(Account& acc, double amount);
    void display(const Account& acc);
};

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount);
};

void Manager::deposit(Account& acc, double amount) {
    if (amount > 0) {
        acc.balance += amount;
    }
}

void Manager::withdraw(Account& acc, double amount) {
    if (amount > 0 && amount <= acc.balance) {
        acc.balance -= amount;
    } else {
        cout << "Insufficient balance or invalid amount in account " << acc.accountNumber << endl;
    }
}

void Manager::display(const Account& acc) {
    cout << "Account Number: " << acc.accountNumber << ", Balance: " << acc.balance << endl;
}

void transferFunds(Account& from, Account& to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
    } else {
        cout << "Transfer failed: insufficient funds or invalid amount." << endl;
    }
}

int main() {
    Account acc1(1001, 5000);
    Account acc2(1002, 3000);

    Manager mgr;

    mgr.display(acc1);
    mgr.display(acc2);

    mgr.deposit(acc1, 2000);
    mgr.withdraw(acc2, 1000);

    cout << "\nAfter deposit and withdrawal:\n";
    mgr.display(acc1);
    mgr.display(acc2);

    transferFunds(acc1, acc2, 1500);

    cout << "\nAfter transferring 1500 from acc1 to acc2:\n";
    mgr.display(acc1);
    mgr.display(acc2);

    return 0;
}

