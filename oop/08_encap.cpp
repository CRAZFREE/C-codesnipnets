#include<bits/stdc++.h>

using namespace std;

class Banking{
    private:
        string accountNumber;
        double balance;

    public:

    Banking(string accNum, double initialBalance){
        accountNumber = accNum;
        balance = initialBalance;
    }

    // getter for the balance
    double getBalance(){
        return balance;
    }

    void deposit(double amount){
        if(amount > 0){
            balance += amount;
            cout << "Amount Deposited successfully" << endl;
        }
        else{
            cout << "Invalid amount" << endl;
        }
    }

    void withDraw(double amount){
        if(amount > 0 && amount <= balance){
            balance -= amount;
            cout << "WithDrawn successfully " << endl;
        }
        else{
            cout << "Invalid amount" << endl;
        }
    }

};

int main(){
    Banking myAccount("4567893",1000);

    cout << myAccount.getBalance() <<endl;

    myAccount.deposit(1000);
    myAccount.withDraw(345);

    cout << myAccount.getBalance()<<endl;

    return 0;

}