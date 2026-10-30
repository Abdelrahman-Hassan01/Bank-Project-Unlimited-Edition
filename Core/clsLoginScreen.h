#pragma once
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"
class clsLoginScreen : private clsScreen
{

  private:
    static void _AuthenticateUser()
    {
        bool LoginFailed = false;
        string UserName, Password;
        int AttemptsRemaining = 3;

        do
        {
            if (LoginFailed && AttemptsRemaining >= 1)
            {
                system("cls");
                _DrawScreenHeader("\t  Login Screen");
                AttemptsRemaining--;
                cout << "\n  Login failed: invalid username or password.\n";
                cout << "  Attempts remaining: " << AttemptsRemaining << " of 3\n\n";
            }

            cout << "  " << left << setw(30) << "Enter username" << " : ";
            UserName = clsInputValidate::ReadString();

            cout << "  " << left << setw(30) << "Enter password" << " : ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFailed = CurrentUser.IsEmpty();

            if (AttemptsRemaining <= 1)
            {
                system("cls");
                cout << "\n  No attempts remain. System locked.\n";
                --AttemptsRemaining;
                IsExitRequested = true;
            }

        } while (LoginFailed && AttemptsRemaining > 1);
        if (!LoginFailed)
        {
            CurrentUser.RegisterLogin();
            clsMainScreen::ShowMainMenu();
        }
    }

  public:
    static void ShowLoginScreen()
    {
        IsExitRequested = false;

        while (!IsExitRequested)
        {
            system("cls");
            _DrawScreenHeader("\t  Login Screen");

            _AuthenticateUser();
        }
    }
};
