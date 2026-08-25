#include <iostream>

using namespace std;


class BankAccount{
    private:
    string owner;
    double balance;

    public:

    BankAccount(string owner, double balance)
    {
        this -> owner = owner;
        this -> balance = balance;
    }

    void deposit(double amount)
    {
        balance = balance + amount;
        cout << "deposited amount of: "<< amount << " updated balance is " << balance << endl;
    }

    void withdraw(double amount)
    {
        if(balance < amount)
        {
            cout << "insufficient balance" << "\n";
        }
        else if(balance >= amount)
        {
            balance = balance - amount;
            cout << "withdrawn amount of: "<< amount << " updated balance is " << balance << endl;
        }      
    }


    friend void transfer(BankAccount& from, BankAccount& to, double amount);
};

void transfer(BankAccount& from, BankAccount& to, double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid transfer amount" << endl;
        return;
    }

    if (from.balance < amount)
    {
        cout << "Insufficient balance for transfer" << endl;
        return;
    }

    if (&from == &to)
    {
        cout << "Cannot transfer to the same account" << endl;
        return;
    }

    from.balance -= amount;
    to.balance += amount;

    cout << "Transferred: " << amount << endl;
}

int main()
{
    BankAccount arnav("Arnav", 1000);
    BankAccount rahul("Rahul", 500);

    arnav.deposit(200);
    rahul.withdraw(100);

    transfer(arnav, rahul, 300);
}