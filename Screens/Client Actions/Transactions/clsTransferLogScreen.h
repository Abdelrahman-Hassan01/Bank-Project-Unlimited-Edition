#pragma once
#include "../../../Core/clsScreen.h"

class clsTransferLogScreen : private clsScreen
{
  private:
    static void _PrintTransferLogRecord(clsBankClient::stTransferLog TransferLog)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLog.TransferDateTime;
        cout << "| " << setw(8) << left << TransferLog.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLog.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLog.TransferAmount;
        cout << "| " << setw(10) << left << TransferLog.SourceBalanceAfterTransfer;
        cout << "| " << setw(10) << left << TransferLog.DestinationBalanceAfterTransfer;
        cout << "| " << setw(8) << left << TransferLog.UserName;
    }

  public:
    static void ShowTransferLogScreen()
    {
        vector<clsBankClient::stTransferLog> vTransferLogs = clsBankClient::GetTransferLogs();
        string Title = "\t  Transfer Log List Screen";
        string SubTitle = "\t   (" + to_string(vTransferLogs.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);
        cout << "\n        -----------------------------------------------------------------------------------------\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << "\n        _________________________________________________________________________________________\n\n";

        if (vTransferLogs.size() == 0)
            cout << "\t\t\t\tNo transfer records available.";
        else

            for (const clsBankClient::stTransferLog &Record : vTransferLogs)
            {

                _PrintTransferLogRecord(Record);
                cout << endl;
            }
        cout << "\n        _________________________________________________________________________________________\n\n";
    }
};
