#pragma once
#include "../../../Core/clsScreen.h"

class clsDepositScreen : private clsScreen
{
  private:
    static void _PrintClientDetails(clsBankClient &Client)
    {
        cout << "\nClient Card\n";
        cout << "---------------------------------------------\n";
        cout << "  " << left << setw(22) << "First Name" << " : " << Client.FirstName << endl;
        cout << "  " << left << setw(22) << "Last Name" << " : " << Client.LastName << endl;
        cout << "  " << left << setw(22) << "Full Name" << " : " << Client.FullName() << endl;
        cout << "  " << left << setw(22) << "Email" << " : " << Client.Email << endl;
        cout << "  " << left << setw(22) << "Phone" << " : " << Client.GetPhone() << endl;
        cout << "  " << left << setw(22) << "Account Number" << " : " << Client.AccountNumber() << endl;
        cout << "  " << left << setw(22) << "Balance" << " : " << Client.AccountBalance << endl;
        cout << "---------------------------------------------\n";
    }

  public:
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t  Deposit Screen");

        cout << "  " << left << setw(30) << "Enter account number" << " : ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::ClientExists(AccountNumber))
        {
            cout << "\nClient with Account Number [" << AccountNumber << "] does not exist.\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClientDetails(Client);

        double Amount = clsInputValidate::ReadDblNumber("Please Enter Deposit Amount? ");

        char Perform = 'n';
        cout << "\nAre you sure you want to perform this transaction? (Y/N)? ";

        cin >> Perform;

        if (Perform == 'y' || Perform == 'Y')
        {

            if (Client.Deposit(Amount))
            {

                cout << "\nDeposit Done Successfully. New balance is: " << Client.AccountBalance + Amount << endl;
            }
        }

        else

            cout << "Operation was canceled.\n";
    }
};
