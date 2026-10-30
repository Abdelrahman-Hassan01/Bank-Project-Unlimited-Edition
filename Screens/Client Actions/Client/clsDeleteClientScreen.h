#pragma once
#include "../../../Core/clsScreen.h"

class clsDeleteClientScreen : private clsScreen
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
    static void ShowDeleteClientScreen()
    {

        string AccountNumber = "";
        _DrawScreenHeader("\tDelete Client Screen");
        cout << "  " << left << setw(30) << "Enter account number" << " : ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::ClientExists(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientDetails(Client1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClientDetails(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};
