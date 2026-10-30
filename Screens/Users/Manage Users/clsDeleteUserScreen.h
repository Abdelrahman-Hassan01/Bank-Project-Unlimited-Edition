#pragma once
#include "../../Core/clsScreen.h"

class clsDeleteUserScreen : public clsScreen
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
    static void ShowDeleteUserScreen()
    {

        string Username = "";
        _DrawScreenHeader("\t  Delete User Screen");
        cout << "  " << left << setw(30) << "Enter username" << " : ";
        Username = clsInputValidate::ReadString();
        while (!clsUser::UserExists(Username))
        {
            cout << "\nUsername is not found, choose another one: ";
            Username = clsInputValidate::ReadString();
        }

        clsUser Userr1 = clsUser::Find(Username);
        _PrintUserDetails(Userr1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (Userr1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintUserDetails(Userr1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};
