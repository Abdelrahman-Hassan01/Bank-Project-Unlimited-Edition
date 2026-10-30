#pragma once
#include "../../Core/clsScreen.h"

class clsFindUserScreen : private clsScreen
{
  private:
    static void _PrintUserDetails(clsUser User)
    {
        cout << "\nUser Card\n";
        cout << "---------------------------------------------\n";
        cout << "  " << left << setw(22) << "First Name" << " : " << User.FirstName << endl;
        cout << "  " << left << setw(22) << "Last Name" << " : " << User.LastName << endl;
        cout << "  " << left << setw(22) << "Full Name" << " : " << User.FullName() << endl;
        cout << "  " << left << setw(22) << "Email" << " : " << User.Email << endl;
        cout << "  " << left << setw(22) << "Phone" << " : " << User.GetPhone() << endl;
        cout << "  " << left << setw(22) << "Username" << " : " << User.UserName << endl;
        cout << "  " << left << setw(22) << "Permissions" << " : " << User.Permissions << endl;
        cout << "---------------------------------------------\n";
    }

  public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tFind User Screen");
        string Username;
        cout << "  " << left << setw(30) << "Enter username" << " : ";
        Username = clsInputValidate::ReadString();

        while (!clsUser::UserExists(Username))
        {
            cout << "User Is Not Found , Choose Another One: ";
            Username = clsInputValidate::ReadString();
        }
        clsUser User1 = clsUser::Find(Username);
        if (!User1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }

        _PrintUserDetails(User1);
    }
};
