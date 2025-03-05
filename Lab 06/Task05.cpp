#include <iostream>
using namespace std;

class Account
{
    int accountnumber;
    float balance;

public:
    Account(int acc, float bal) : accountnumber(acc), balance(bal) {}
    void display()
    {
        cout << "Account Number: " << accountnumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Savingsaccount:  public Account{
    int interestrate;

    public:
    Savingsaccount(int acc, float bal, int ir): Account(acc, bal), interestrate(ir){}

    void display(){
        Account::display();
        cout << "Interest Rate: " << interestrate << endl;
    }



};

class Currentaccount: public Account{
    int overdraftlimit;

    public:
    Currentaccount(int acc, float bal, int odl): Account(acc, bal), overdraftlimit(odl){}

    void display(){
        Account::display();
        cout << "Overdraft Limit: " << overdraftlimit << endl;
    }
};

int main(){

    Savingsaccount s(123, 1000, 5);
    Currentaccount c(456, 2000, 1000);

    s.display();
    c.display();

    return 0;

}
