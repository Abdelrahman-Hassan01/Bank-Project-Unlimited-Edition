#pragma once
#include "../../../Core/clsScreen.h"
class clsWithdrawScreen : private clsScreen
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
    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t  Withdraw Screen");

        cout << "  " << left << setw(30) << "Enter account number" << " : ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::ClientExists(AccountNumber))
        {
            cout << "\nClient with Account Number [" << AccountNumber << "] does not exist ";

            cout << "Choose Another One: ";

            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _PrintClientDetails(Client);

        double Amount;

        while (true)
        {

            cout << "  " << left << setw(30) << "Enter withdrawal amount" << " : ";
            Amount = clsInputValidate::ReadDblNumber();

            if (Amount <= Client.AccountBalance)

                break;

            cout << setw(37) << left << "\nAmount Exceeds The Balance.";

            cout << setw(37) << left << "\nYou Can Withdraw Up To: " + to_string(Client.AccountBalance);

            cout << setw(37) << left << "\n\n[1] Withdraw Again\n[2] Back To Transaction Menu\nChoice: ";

            int Choice = clsInputValidate::ReadShortNumberBetween(1, 2);

            if (Choice == 2)

                return;
        }

        char Perform;

        cout << "\nAre you sure you want to perform this transaction? (Y/N)? ";

        cin >> Perform;

        if (Perform == 'y' || Perform == 'Y')

        {

            if (Client.Withdraw(Amount))
            {
                cout << "\nWithdraw Done Successfully. New balance is: " << Client.AccountBalance << endl;
            }
        }

        else

            cout << "Operation was canceled.\n";
    }
};
