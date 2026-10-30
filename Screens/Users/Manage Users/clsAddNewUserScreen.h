#pragma once
#include "../../Core/clsScreen.h"

class clsAddNewUserScreen : private clsScreen

{
  private:
    static void _ReadUserDetails(clsUser &User)
    {
        cout << "  " << left << setw(30) << "Enter first name" << " : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "  " << left << setw(30) << "Enter last name" << " : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "  " << left << setw(30) << "Enter email" << " : ";
        User.Email = clsInputValidate::ReadString();

        cout << "  " << left << setw(30) << "Enter phone" << " : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "  " << left << setw(30) << "Enter password" << " : ";
        User.Password = clsInputValidate::ReadString();

        cout << "  " << left << setw(30) << "Enter permissions" << " : ";
        User.Permissions = _ReadPermissions();
    }

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

    static int _ReadPermissions()
    {
        char answer;
        int Permission = 0;
        cout << "\nDo You Want Give All Permission ? Y/N: ";

        cin >> answer;

        if (answer == 'y')
            return Permission = int(clsUser::enPermissions::eAll);

        cout << "\nShow Client List Y/N: ";

        cin >> answer;

        if (answer == 'y')
            Permission += int(clsUser::enPermissions::pListClients);

        cout << "\nAdd New Client? Y/N: ";

        cin >> answer;

        if (answer == 'y')
            Permission += int(clsUser::enPermissions::pAddNewClient);

        cout << "\nDelete Client? Y/N: ";

        cin >> answer;

        if (answer == 'y')
            Permission += int(clsUser::enPermissions::pDeleteClient);

        cout << "\nUpdate Client? Y/N: ";

        cin >> answer;

        if (answer == 'y')
            Permission += int(clsUser::enPermissions::pUpdateClients);

        cout << "\nFind Client? Y/N: ";

        cin >> answer;

        if (answer == 'y')
            Permission += int(clsUser::enPermissions::pFindClient);

        cout << "\nTransactions? Y/N: ";

        cin >> answer;

        if (answer == 'y')
            Permission += int(clsUser::enPermissions::pTransactions);

        cout << "\nManage Users? Y/N: ";

        cin >> answer;

        if (answer == 'y' && Permission == 63)
        {
            Permission += int(clsUser::enPermissions::pManageUsers);
        }

        else
            cout << "!!!Access Denied You Need Have Access For Full System!!!";

        cout << "Show Login Register? Y/N? ";
        cin >> answer;

        if (answer == 'y')
        {
            Permission += int(clsUser::enPermissions::pLoginRegister);
        }
        
        cout << "Currency Exchange? Y/N? ";
        cin >> answer;

        if (answer == 'y')
        {
            Permission += int(clsUser::enPermissions::pCurrency);
        }
        return Permission;
    }

  public:
    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\t  Add New User Screen");
        cout << "  " << left << setw(30) << "Enter username" << " : ";
        string UserName = clsInputValidate::ReadString();

        while (clsUser::UserExists(UserName))
        {
            cout << "User with username [" << UserName << "] exist.\n";
            UserName = clsInputValidate::ReadString();
        }
        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserDetails(NewUser);

        clsUser::enSaveResults SaveResults;

        SaveResults = NewUser.Save();

        switch (SaveResults)
        {
        case clsUser::enSaveResults::svSucceeded:
            cout << "\n User Added Succefully";
            _PrintUserDetails(NewUser);

            break;

        case clsUser::enSaveResults::svFailedEmptyObject:

            cout << "\n Error User Was Not Saved Because It's Empty ";
            break;
        }
    }
};
