#pragma once
#include "../../../Core/clsScreen.h"

class clsAddNewClientScreen : public clsScreen
{
  private:
    static void _ReadClientDetails(clsBankClient &Client)
    {

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
    static void ShowAddNewClientScreen()
    {
        string AccountNumber = "";
        _DrawScreenHeader("\t  Add New Client Screen");
        cout << "  " << left << setw(30) << "Enter account number" << " : ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::ClientExists(AccountNumber))
        {
            cout << "\n\tAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientDetails(NewClient);
        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded: {
            cout << "\n\tAccount Updated Successfully :-)\n";
            _PrintClientDetails(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFailedEmptyObject: {
            cout << "\n\tError account was not saved because it's Empty";
            break;
        }
        case clsBankClient::enSaveResults::svFailedAccountNumberExists: {
            cout << "\n\tError account was not saved because account number is used!\n";
            break;
        }
        }
    }
};
