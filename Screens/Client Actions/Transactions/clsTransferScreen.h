#pragma once
#include "../../../Core/clsScreen.h"
class clsTransferScreen : protected clsScreen

{
  private:
    static void _PrintClientRecord(clsBankClient Client)
    {
        cout << "\nClient Card\n";
        cout << "---------------------------------------------\n";
        cout << "  " << left << setw(22) << "Full Name" << " : " << Client.FullName() << endl;
        cout << "  " << left << setw(22) << "Account Number" << " : " << Client.AccountNumber() << endl;
        cout << "  " << left << setw(22) << "Account Balance" << " : " << Client.AccountBalance << endl;
        cout << "---------------------------------------------\n";
    }

  public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t  Transfer Screen");
        string FromAccountNumber;
        cout << "  " << left << setw(30) << "Transfer from account number" << " : ";
        FromAccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::ClientExists(FromAccountNumber))
        {
            cout << "Account does not exist. Enter another account number: ";
            FromAccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient From = clsBankClient::Find(FromAccountNumber);
        cout << endl;

        _PrintClientRecord(From);

        cout << "  " << left << setw(30) << "Transfer to account number" << " : ";
        string ToAccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::ClientExists(ToAccountNumber))
        {
            cout << "Account does not exist. Enter another account number: ";
            ToAccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient To = clsBankClient::Find(ToAccountNumber);

        _PrintClientRecord(To);

        cout << "  " << left << setw(30) << "Enter transfer amount" << " : ";
        double Amount = clsInputValidate::ReadDblNumber();

        while (Amount > From.AccountBalance)
        {

            cout << "Amount exceeds the available balance or is less than 1. Enter another amount: ";

            Amount = clsInputValidate::ReadDblNumber();
        }

        cout << "\n\nDo you want to perform this transfer? (Y/N): ";

        char Answer;

        cin >> Answer;

        if (Answer == 'y')
        {

            if (From.Transfer(To, Amount))
            {
                system("cls");
                cout << "\n\nTransfer Done Successfully.\n\n";

                From.RegisterTransferLog(To, Amount);
                _PrintClientRecord(From);
                cout << endl;
                _PrintClientRecord(To);
            }
        }
        else

            cout << "Transfer canceled.\n\n";

        cout << "Do you want to make another transfer? (Y/N): ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            system("cls");
            ShowTransferScreen();
        }
    }
};
