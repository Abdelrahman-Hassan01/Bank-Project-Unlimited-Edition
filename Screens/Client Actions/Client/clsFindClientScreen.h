#pragma once
#include "../../../Core/clsScreen.h"

class clsFindClientScreen : private clsScreen
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
    static void ShowFindClientScreen()
    {
        _DrawScreenHeader("\tFind Client Screen");
        string AccountNumber;
        cout << "  " << left << setw(30) << "Enter account number" << " : ";
        AccountNumber = clsInputValidate::ReadString();

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }
        _PrintClientDetails(Client1);
    }
};
