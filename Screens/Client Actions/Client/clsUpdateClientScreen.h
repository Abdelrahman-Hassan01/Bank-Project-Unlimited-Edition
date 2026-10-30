#pragma once
#include "../../../Core/clsScreen.h"

class clsUpdateClientScreen : private clsScreen
{
  private:
    static void _ReadClientDetails(clsBankClient &Client)
    {
        string FirstName, LastName, Email, Phone, PinCode;
        float AccountBalance;
        cout << "  " << left << setw(30) << "Enter first name" << " : ";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "  " << left << setw(30) << "Enter last name" << " : ";
        Client.LastName = clsInputValidate::ReadString();
        cout << "  " << left << setw(30) << "Enter email" << " : ";
        Client.Email = clsInputValidate::ReadString();
        cout << "  " << left << setw(30) << "Enter phone" << " : ";
        Client.Phone = clsInputValidate::ReadString();
        cout << "  " << left << setw(30) << "Enter PIN code" << " : ";
        Client.PinCode = clsInputValidate::ReadString();
        cout << "  " << left << setw(30) << "Enter balance" << " : ";
        Client.AccountBalance = clsInputValidate::ReadDblNumber();
    }

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
    static void ShowUpdateClientScreen()
    {
        _DrawScreenHeader("\tUpdate Client Screen");
        string AccountNumber = "";

        cout << "  " << left << setw(30) << "Enter account number" << " : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::ClientExists(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientDetails(Client1);

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        _ReadClientDetails(Client1);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded: {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClientDetails(Client1);
            break;
        }
        case clsBankClient::enSaveResults::svFailedEmptyObject: {
            cout << "\nError account was not saved because it's Empty";
            break;
        }
        }
    }
};
