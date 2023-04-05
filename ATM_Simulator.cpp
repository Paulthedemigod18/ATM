// This is the Code for my Computer Science Programming Module//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Account
{
    int Account_no;
    double Account_balance;
    
};

class ATM_Simulator
{
    private:
    Account* account;

    public:
     ATM_Simulator(Account* acct);

    void performTransaction();
};


void performTransaction()
{
    string continueTransaction;
    cout << "Would you like to perform another transaction? (Yes/No)" << endl;
    cin >> continueTransaction;
    if (continueTransaction == "yes")
    {
        return;
}
    else if (continueTransaction == "no")
    {
        exit(0);
    }
    else
    {
        cout << "Invalid input" << endl;
        exit(1);
    }
}

int main()
{
    // Initialize balance to $1000
    double balance = 0;
    double withdrawalAmount;
    double transferAmount;
    int recipientAccountno;
    int response;
    int depositorAccountno;
    int depositAmount;
    // Display ATM interface
    int run = 1;
    do
    {
        cout << "Welcome to the ATM!" << endl;
        cout << "1.Withdrawal" << endl;
        cout << "2.Check Balance" << endl;
        cout << "3.Transfer" << endl;
        cout << "4. Deposit" << endl;

        // Get user response
        cin >> response;

        if (response == 1)
        {
            // Prompt user for withdrawal amount
            cout << "Please enter the amount you would like to withdraw: ";
            cin >> withdrawalAmount;

            // Check if withdrawal amount is valid
            if (withdrawalAmount <= balance)
            {
                // Update balance and display message
                balance -= withdrawalAmount;
                cout << "You have successfully withdrawn £" << withdrawalAmount << endl;
                cout << "Your new balance is £" << balance << endl;
            }
            else
            {
                // Display error message
                cout << "You do not have enough funds for this withdrawal" << endl;
            }
        }
        else if (response == 2)
        // Show available Balance
        {
            cout << "Your Account Balance is £" << balance << endl;
        }
        else if (response == 3)
        // Option to Transfer Money to another account
        {
            cout << "Enter Recipient Account Number";
            cin >> recipientAccountno;
            cout << "Enter Transfer Amount";
            cin >> transferAmount;
            if (transferAmount <= balance)
            {
                balance -= transferAmount;
                cout << "You have successfully transfered £" << transferAmount << endl;
                cout << "Your new balance is £" << balance << endl;
            }
            else
            {
                cout << "You do not have enough funds for this transfer" << endl;
            }
        }
        else if (response == 4)
        // Option to deposit Money into the account
        {
            cout << "Enter Depositor's Account Number";
            cin >> depositorAccountno;
            cout << "Enter Deposit Amount";
            cin >> depositAmount;
            balance += depositAmount;
            cout << "You have successfully deposited £" << depositAmount << endl;
            cout << "Your new balance is £" << balance << endl;
        }

        else
        {
            // Recall the perform transaction function
            performTransaction();
            // Display exit message
            cout << "Thank you for using the ATM!" << endl;
        }
    }while(run==1);
     return 0;
 }

