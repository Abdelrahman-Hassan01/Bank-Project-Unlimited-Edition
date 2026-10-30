#pragma once
#include "../../Core/clsScreen.h"

class clsLoginRegisterScreen : protected clsScreen
{
  private:
    static void _PrintLoginRegisterRecord(clsUser::stLoginRegisterRecord User)
    {

        cout << "| " << setw(34) << left << User.DateTime;
        cout << "| " << setw(19) << left << User.UserName;
        cout << "| " << setw(19) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;
    }

  public:
    static void ShowLoginRegisterScreen()
    {
        vector<clsUser::stLoginRegisterRecord> vLogs = clsUser::GetLoginRegisterRecords();
        string Title = "\t  Login Register Screen";
        string SubTitle = "\t   (" + to_string(vLogs.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);
        cout << "\n--------------------------------------------------------------------------------------------\n\n";

        cout << "| " << setw(34) << left << "Date/Time";
        cout << "| " << setw(19) << left << "UserName";
        cout << "| " << setw(19) << left << "Password";
        cout << "| " << setw(12) << left << "Permissions\n";
        cout << "\n____________________________________________________________________________________________\n\n";

        if (vLogs.size() == 0)
            cout << "\t\t\t\tNo login records available.";
        else

            for (const clsUser::stLoginRegisterRecord &Record : vLogs)
            {

                _PrintLoginRegisterRecord(Record);
                cout << endl;
            }
        cout << "\n____________________________________________________________________________________________\n\n";
    }
};
