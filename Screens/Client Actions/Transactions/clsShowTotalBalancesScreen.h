#pragma once
#include "../../../Core/clsScreen.h"
class clsShowTotalBalancesScreen : private clsScreen
{
  private:
    static void _PrintClientBalanceRow(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

  public:
    static void ShowTotalBalancesScreen()
    {

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t Balances List Screen ";
        string subTitle = "\t  (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, subTitle);
        cout << "\n_________________________________________________________________________\n\n";

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_________________________________________________________________________\n\n";

        double TotalBalances = clsBankClient::GetTotalClientBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                _PrintClientBalanceRow(Client);
                cout << endl;
            }
        cout << "\n_________________________________________________________________________\n\n";
        cout << "\n  Total balances : " << TotalBalances << endl;
        cout << "  Amount in words: " << clsUtil::NumberToText(TotalBalances) << endl;
    }
};
