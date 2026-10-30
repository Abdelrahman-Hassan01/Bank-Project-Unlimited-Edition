#pragma once
#include "../../Core/clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsersScreen : private clsScreen
{
  private:
    enum class enManageUsersMenuOption
    {
        eListUsers = 1,
        eAddNewUser,
        eDeleteUser,
        eUpdateUser,
        eFindUser,
        eMainMenu
    };

    static void _ReturnToManageUsersMenu()
    {
        cout << setw(37) << left << " " << "\nPress any key to go back to manage users...\n";
        system("pause>0");
        ShowManageUsersMenu();
    }
    static short _ReadManageUsersMenuOption()
    {
        cout << setw(37) << left << "" << "Choose an option (1-6): ";

        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
        return Choice;
    }

    static void _ListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();
    }

    static void _AddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _DeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _UpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _FindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _HandleManageUsersMenuOption(enManageUsersMenuOption MenuOption)
    {
        int counter = 1;

        switch (MenuOption)
        {
        case enManageUsersMenuOption::eListUsers:
            system("cls");
            _ListUsersScreen();
            _ReturnToManageUsersMenu();
            break;
        case enManageUsersMenuOption::eAddNewUser:
            system("cls");
            _AddNewUserScreen();
            _ReturnToManageUsersMenu();
            break;
        case enManageUsersMenuOption::eDeleteUser:
            system("cls");
            _DeleteUserScreen();
            _ReturnToManageUsersMenu();
            break;
        case enManageUsersMenuOption::eUpdateUser:
            system("cls");
            _UpdateUserScreen();
            _ReturnToManageUsersMenu();
            break;
        case enManageUsersMenuOption::eFindUser:
            system("cls");
            _FindUserScreen();
            _ReturnToManageUsersMenu();
            break;
        case enManageUsersMenuOption::eMainMenu:
            system("cls");
            break;
        }
    }

  public:
    static void ShowManageUsersMenu()
    {
        system("cls");
        _DrawScreenHeader("Manage Users Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _HandleManageUsersMenuOption(enManageUsersMenuOption(_ReadManageUsersMenuOption()));
    }
};
