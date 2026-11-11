#include <iostream>
using namespace std;

class SavingsAccount {
private:
    int accountNo;
    double balance;
    double transactions[10];
    int count;

    void addTransaction(double amount) {
        if (count == 10) {
            for (int i = 1; i < 10; i++) {
                transactions[i - 1] = transactions[i];
            }
            count--;
        }
        transactions[count++] = amount;
    }

public:
    SavingsAccount(int number, double openingBalance)
        : accountNo(number), balance(openingBalance), count(0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction(amount);
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            addTransaction(-amount);
        } else {
            cout << "Withdrawal not allowed\n";
        }
    }

    void miniStatement();
};

void SavingsAccount::miniStatement() {
    cout << "Account: " << accountNo << '\n';
    cout << "Balance: " << balance << '\n';
    cout << "Transactions:\n";
    for (int i = 0; i < count; i++) {
        cout << transactions[i] << '\n';
    }
}

int main() {
    SavingsAccount account(101, 5000);
    account.deposit(1000);
    account.withdraw(500);
    account.miniStatement();

    return 0;
}