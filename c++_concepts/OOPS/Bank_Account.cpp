#include <iostream>
#include <format>
using namespace std;


/*Design a BankAccount class with private data members like accountNumber, accountHolderName, and balance. 
Include public methods to deposit(), withdraw(), and displayAccountDetails(). 
Add a minimum balance check to prevent overdrafts.*/
class BankAccount
{
    private:
    string accountNumber;
    string accountHolderName;
    float balance;

    public:
    BankAccount(string accNo, string name, float initialBalance)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = initialBalance;
    }

    public:
    void deposit(int amount)
    {
        balance = balance + amount;
        cout << "Amount of " << amount << " is being deposited and updated balance is " << balance << endl;
        
    }

    void withdraw(int amount)
    {
        if (amount > balance)
        {
            cout <<  "insufficient balance";
        }
        else
        {
            balance -= amount;
            cout << "Amount of " << amount << " is being withdrawed and updated balance is " << balance << endl;
        }
    }

    
};


int main()
{
    BankAccount customer1(
        "123456789",
        "Arnav",
        5000
    );

    customer1.deposit(3000);
    customer1.withdraw(2000);

    return 0;
}